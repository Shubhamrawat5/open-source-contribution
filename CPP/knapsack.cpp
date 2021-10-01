#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &val, vector<int> &weights, int capacity)
{
    vector<vector<int>> dp(val.size() + 1, vector<int>(capacity + 1, 0));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j >= weights[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j - weights[i - 1]] + val[i - 1], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[val.size()][capacity];
}

int main()
{
    int n;
    cin >> n;
    vector<int> val(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i] >> weights[i];
    }
    int capacity;
    cin >> capacity;
    int ans = knapsack(val, weights, capacity);
    cout << ans << endl;
    return 0;
}
