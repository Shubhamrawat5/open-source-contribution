def canJump(nums):
    max_reach = 0
    for i in range(len(nums)):
        if i > max_reach:
            return False
        max_reach = max(max_reach, i + nums[i])
        if max_reach >= len(nums) - 1:
            return True
    return True

nums = list(map(int, input("Enter a list of non-negative integers separated by spaces: ").split()))
result = canJump(nums)
if result:
    print("It's possible to reach the last index.")
else:
    print("It's not possible to reach the last index.")
