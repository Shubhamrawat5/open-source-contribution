# https://leetcode.com/submissions/detail/1406798274/
# By Sarthak Roy
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        x=[]
        for i in nums:
            if i != 0:
                x.append(i)
        for i in range(nums.count(0)):
            x.append(0)
        for i in range(len(nums)):
            nums[i]=int(x[i])
