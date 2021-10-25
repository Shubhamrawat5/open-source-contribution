// Partition equal subset sum

#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

//Function to check if subsets can be partitioned equally or not
bool isPartition(vector<int>a)
{
    int n=a.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }

    if(sum & 1) return false;  // if sum is odd then it's not possible for partiton
    bool dp[n+1][sum/2+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum/2;j++)
        {
            if(i==0 or j==0) dp[i][j]=false;    // base condition
            else if(a[i-1] > j) dp[i][j]=dp[i-1][j];        //if current value > current sum then skip
            else if(a[i-1]==j) dp[i][j]=true;       // if current sum == current value then it's possible 
            else dp[i][j]=dp[i-1][j] or dp[i-1][j-a[i-1]];  // knapsack condition, either to include or exclude depending upon value
        }
    }
    
    return dp[n][sum/2];
        
}

int main()
{
    int n;
    cin>>n;
    vector<int>a;

    while(n--)
    {
        int data;
        cin>>data;
        a.push_back(data);
    }
    if(isPartition(a)==true) cout<<"Yes";
    else cout<<"No";
    cout<<endl;
    return 0;
}