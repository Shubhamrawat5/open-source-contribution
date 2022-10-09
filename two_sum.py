# Program to find all pairs whose sum is equal to target.


print("Enter the size of array")
n = int(input())
print("Enter elements of the array seperated by space")
nums = list(map(int, input().split()))
print("Enter The target to find in array")
target = int(input())
hashmap = {}
ans = []
for i in range(len(nums)):
    complement = target - nums[i]  # check if the compiment id available in hashmap
    if complement in hashmap:
        ans.append([nums[i], complement])  # if available then store the pair
    hashmap[nums[i]] = i  # add current element in hashmap
print(ans)
