class Disk:
    def __init__(self, filename):
        self.file = open(filename, 'r+b')
        self.reads = 0
        self.writes = 0

    def readBlock(self, block_num):
        self.file.seek(block_num * 512)
        data = self.file.read(512)
        self.reads += 1
        return data

    def writeBlock(self, block_num, data):
        self.file.seek(block_num * 512)
        self.file.write(data)
        self.writes += 1

    def printStats(self):
        print(f"Reads: {self.reads}, Writes: {self.writes}")

    def close(self):
        self.file.close()
