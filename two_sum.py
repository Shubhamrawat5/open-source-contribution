print("Enter the size of the array:")
n = int(input())
if n <= 0:
    print("Array size must be positive.")
    exit()

print("Enter elements of the array separated by space:")
nums = list(map(int, input().split()))
if len(nums) != n:
    print(f"Expected {n} elements, but got {len(nums)}.")
    exit()

print("Enter the target to find in the array:")
target = int(input())

hashmap = {}
ans = set()  # Using a set to avoid duplicate pairs

for num in nums:
    complement = target - num
    if complement in hashmap:
        # Create a sorted tuple to store pairs uniquely
        ans.add(tuple(sorted((num, complement))))  
    hashmap[num] = hashmap.get(num, 0) + 1  # Count occurrences

# Convert set of tuples back to a list for output
ans_list = list(ans)

if ans_list:
    print("Pairs that sum to", target, "are:")
    for pair in ans_list:
        print(pair)
else:
    print("No pairs found.")
