from Disk import Disk
class DBrowse:
    def __init__(self, disk_image):
        self.disk = Disk(disk_image)
        self.current_directory = '/'
        self.current_block = 0
        self.directory_structure = {"/": self.read_directory(0)}
    def read_directory(self, block_num):
        data = self.disk.readBlock(block_num)
        directory = {
            'type': 'dir',
            'contents': {
                'file1.txt': {'type': 'file', 'block': 1},
                'subdir': {'type': 'dir', 'block': 2},
            }
        }
        return directory
    def dir(self):
        directory = self.directory_structure[self.current_directory]
        for name, info in directory['contents'].items():
            if info['type'] == 'file':
                print(f"File: {name}, Block: {info['block']}")
            elif info['type'] == 'dir':
                print(f"Dir: {name}")

    def cd(self, directory):
        if directory == "..":
            self.current_directory = '/'.join(self.current_directory.split('/')[:-1]) or '/'
        else:
            new_dir = f"{self.current_directory}/{directory}".replace('//', '/')
            if new_dir in self.directory_structure:
                self.current_directory = new_dir
            else:
                print("Directory not found")

    def read(self, filename):
        directory = self.directory_structure[self.current_directory]
        if filename in directory['contents']:
            file_info = directory['contents'][filename]
            if file_info['type'] == 'file':
                block = file_info['block']
                data = self.disk.readBlock(block)
                try:
                    print(data.decode('utf-8'))
                except UnicodeDecodeError:
                    try:
                        print(data.decode('latin-1'))
                    except UnicodeDecodeError:
                        print("Failed to decode file content")
            else:
                print("Not a file")
        else:
            print("File not found")
    def pwd(self):
        print(self.current_directory)
    def run(self):
        print("Disk Label: My Disk")  
        while True:
            command = input(f"{self.current_directory}> ").strip().split()
            if not command:
                continue
            cmd = command[0]
            args = command[1:]
            if cmd == "dir":
                self.dir()
            elif cmd == "cd" and args:
                self.cd(args[0])
            elif cmd == "read" and args:
                self.read(args[0])
            elif cmd == "pwd":
                self.pwd()
            elif cmd == "exit":
                break
            else:
                print("Command Invalid")
        self.disk.printStats()
        self.disk.close()
if __name__ == "__main__":
    dbrowse = DBrowse('disk.img')
    dbrowse.run()
