
# This is just an example, showing how the Disk class can be used.
# Use this as a reference, but you'll need to write your own code.

import Disk

DISK_FILE	= "disk.img"
BLOCK_SIZE	= 512

# Instantiate a new Disk, backed by the user-supplied file
d = Disk.Disk(DISK_FILE, BLOCK_SIZE)

# Write A's to the 0th block on the disk
d.writeBlock(0, (b"A" * BLOCK_SIZE))

# Read the 0th block back off the disk.
# It should be the A's we just wrote
block = d.readBlock(0)

# Print that data out, showing it worked
print("{}".format(block))

# Print statistics showing block read/writes
# Should be one read, one write
d.printStats()

del d
