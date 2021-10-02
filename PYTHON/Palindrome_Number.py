# https://leetcode.com/problems/palindrome-number/
# 9. Palindrome Number
# Given an integer x, return true if x is palindrome integer.

# An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        if x == self.reverse(x):
            return True
        return False

    def reverse(self, num):
        res = 0
        while num != 0:
            res = res * 10 + num % 10
            num /= 10
        return res
