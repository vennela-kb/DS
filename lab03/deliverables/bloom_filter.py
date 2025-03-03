from pybloom_live import BloomFilter

# Here we load names into Bloom Filter
def load_bloom_filter(filename):
    bloom = BloomFilter(capacity=1000, error_rate=0.01)  # Adjusting here the parameters if needed
    with open(filename, "r") as file:
        for line in file:
            bloom.add(line.strip().lower())  # Storing names in lowercase for consistency
    return bloom

# Applying now a "Query function"
def query_name(bloom):
    while True:
        name = input("Enter First and Last Name (or type 'END END' to exit): ").strip().lower()
        if name == "end end":
            print("Exiting program...")
            break
        if name in bloom:
            print(f"\n=================================")
            print(f"Name: {name.title()}")
            print(f"{name.title()} is PROBABLY a Customer (99% Prob.)")
            print("=================================\n")
        else:
            print(f"\n=================================")
            print(f"Name: {name.title()}")
            print(f"{name.title()} is NOT a Customer")
            print("=================================\n")

# Main function
if __name__ == "__main__":
    bloom_filter = load_bloom_filter("list.txt")
    query_name(bloom_filter)
