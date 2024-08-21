from pybloom_live import BloomFilter

def load_names(filename):
    with open(filename, 'r') as file:
        names = file.read().splitlines()
    return names

def main():
    
    bloom_filter = BloomFilter(capacity=100, error_rate=0.1)
    names = load_names('list.txt')
    for name in names:
        bloom_filter.add(name)
    while True:
    
        name = input("Enter the First and Last name (or END END to quit): ")
        if name == "END END":
            break
        if name in bloom_filter:
            print(f"{name} is PROBABLY a Customer (with a probability of {1 - bloom_filter.error_rate})")
        else:
            print(f"{name} is NOT a Customer")

if __name__ == "__main__":
    main()
