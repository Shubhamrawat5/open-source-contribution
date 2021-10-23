#https://leetcode.com/problems/longest-palindromic-substring/
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)==0:
            return ""
        st,stp=0,0
        mat=[[0]*len(s) for i in range(len(s))]
        maxi=0
        for i in range(len(s)):
            mat[i][i]=1
        for l in range(2,len(s)+1):
            for i in range(0, len(s)-l+1):
                j=i+l-1
                if s[i]==s[j] and l==2:
                    mat[i][j]=2
                    if mat[i][j]>maxi:
                        maxi=mat[i][j]
                        st,stp=i,j
                elif s[i]==s[j]:
                    if mat[i+1][j-1]!=0:
                        mat[i][j]=mat[i+1][j-1]+2
                        if mat[i][j]>maxi:
                            maxi=mat[i][j]
                            st,stp=i,j
        return s[st:stp+1]
