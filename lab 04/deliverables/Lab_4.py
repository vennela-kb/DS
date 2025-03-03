import os

class DiskBrowser:
    def __init__(self, disk_image):
        self.disk_image = disk_image
        self.filesystem = {}  # Where the files from disk.img stored
        self.current_directory = os.getcwd()  # This function will providea real working directory
        self.load_filesystem()

    def load_filesystem(self):
        """Load filesystem metadata from disk image."""
        try:
            with open(self.disk_image, "rb") as f:
                data = f.read()
                
                # Here we expec file metadata is stored as null-terminated strings
                file_entries = data.split(b'\x00')

                self.filesystem.clear()
                for entry in file_entries:
                    name = entry.decode(errors='ignore').strip()
                    if name:
                        self.filesystem[name] = None  # This serve as placeholder for file content
                
                print("📀 Disk image loaded successfully.")
        except FileNotFoundError:
            print("❌ Disk image not found.")
        except Exception as e:
            print(f"❌ Error loading disk image: {e}")

    def list_files(self):
        """List both real directory files and disk image files."""
        print("\n📂 Real Filesystem (OS) Contents:")
        try:
            for item in os.listdir(self.current_directory):
                item_path = os.path.join(self.current_directory, item)
                if os.path.isdir(item_path):
                    print(f"📁 {item}/")  # Directory printed
                else:
                    print(f"📄 {item}")  # File printed
        except Exception as e:
            print(f"❌ Error listing real files: {e}")

        print("\n💾 Disk Image Contents:")
        if self.filesystem:
            for file in self.filesystem.keys():
                print(f"📄 {file}")
        else:
            print("📭 No files found in disk.img.")

    def show_current_directory(self):
        """Display the current working directory."""
        print(f"\n📍 Current Directory: {self.current_directory}")

    def change_directory(self, new_directory):
        """Change current working directory."""
        new_path = os.path.join(self.current_directory, new_directory)
        if os.path.isdir(new_path):
            self.current_directory = new_path
            os.chdir(new_path)
        else:
            print(f"❌ Directory '{new_directory}' not found.")

    def read_file(self, filename):
        """Read a file from the disk image."""
        if filename not in self.filesystem:
            print(f"❌ File '{filename}' not found in disk image.")
            return
        
        try:
            with open(self.disk_image, "rb") as f:
                data = f.read()
                start_index = data.find(filename.encode()) + len(filename)  

                if start_index == -1:
                    print(f"❌ File '{filename}' not found in data block.")
                    return
                
                file_data = data[start_index:].split(b'\x00')[1]
                content = file_data.decode(errors='ignore').strip()
                
                print(f"\n📄 Content of {filename}:\n")
                print(content)
        except Exception as e:
            print(f"❌ Error reading file: {e}")

    def show_help(self):
        """Display available commands."""
        print("\n📜 Available Commands:")
        print("  dir          → List files (both OS & disk.img)")
        print("  pwd          → Show current directory")
        print("  read <file>  → Read a file from disk.img")
        print("  cd <dir>     → Change directory")
        print("  help         → Show available commands")
        print("  exit         → Exit the browser")

# Initialize the disk browser
disk_browser = DiskBrowser("disk.img")

# Interactive Command Loop
while True:
    command = input("\ndbrowse> ").strip().lower()
    
    if command == "exit":
        print("👋 Exiting DBrowse.")
        break
    elif command == "dir":
        disk_browser.list_files()
    elif command == "pwd":
        disk_browser.show_current_directory()
    elif command.startswith("cd "):
        new_dir = command[3:].strip()
        disk_browser.change_directory(new_dir)
    elif command.startswith("read "):
        filename = command[5:].strip()
        disk_browser.read_file(filename)
    elif command == "help":
        disk_browser.show_help()
    else:
        print("❌ Unknown command. Use 'help' to see available commands.")
