#https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d={}
        ct=0
        maxct=0
        i=0
        n=len(s)
        st=0
        dind={}
        while i<n:
            if s[i] not in d:
                d[s[i]]=1
                dind[s[i]]=i
                ct+=1
                if ct>maxct:
                    maxct=ct
            else:
                i=dind[s[i]]
                d={}
                ct=0
            i+=1
        return maxct
