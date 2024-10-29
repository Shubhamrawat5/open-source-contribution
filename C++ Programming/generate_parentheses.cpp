#include <bits/stdc++.h>
using namespace std;

void helper(vector<string> &ans, int l, int r, string s)
{

    if (l == 0 && r <= 0)
    {
        ans.push_back(s);
        return;
    }

    if (l > 0)
    {
        helper(ans, l - 1, r, s + '(');
    }

    // har step pe yhi kr skta hu ya to left daalu ya to right daalu right daalte samay left ka count check krna pdega
    if (r > l)
    {
        helper(ans, l, r - 1, s + ')');
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string s = "";
    helper(ans, n, n, s);
    return ans;
}