// Generate Parenthesis Leetcode Problem 22 - https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        findParenthesis(sol, "", n, n);
        return sol;
    }
    
    void findParenthesis(vector<string> &sol, string str, int left, int right)
    {
        if(left==0 && right==0)
        {
            sol.push_back(str);
            return;
        }
        if(left>0)
            findParenthesis(sol, str+"(", left-1, right);
        if(right>left)
            findParenthesis(sol, str+")", left,  right-1);
    }
};
