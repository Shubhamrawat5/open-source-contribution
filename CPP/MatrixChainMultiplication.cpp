//Matrix Chain Multiplication
#include <bits/stdc++.h>
using namespace std;

//Memoiztion Code
//dp[n+1][n+1];
int dp[1001][1001];
int solve(vector<int> v, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(v, i, k) + solve(v, k + 1, j) + v[i - 1] * v[k] * v[j];
        if (mn > temp)
        {
            mn = temp;
        }
    }
    return dp[i][j] = mn;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    int i = 1, j = n - 1;
    int ans = solve(v, i, j);
    cout << "Min Cost of MUltiplication is: " << ans << endl;
    return 0;
}