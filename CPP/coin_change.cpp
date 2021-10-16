// In our problem set, we are given S supply of coins {s1,s2,s3….sn}. We have to make a change for N rupees. We have to count the number of ways in which
// we can make the change. This is the basic coin change problem in c++ which we will solve using dynamic programming.


// Here is the code for the same
#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include<string>
#include<vector>
#include<string.h>
using namespace std;

const int MAX = 1000001;

#define rep(a,b,c) for(int a=b; a<c; a++)
const int N=1e3+2;
int dp[N][N];

int coinchange(vector<int> &a,int n,int x){
    if(x==0){
        return 1;
    }
    if(x<0){
         return 0;
    }
    if(n<=0){
        return 0;
    }
    if(dp[n][x]!=-1){
       return dp[n][x];
    }
    dp[n][x]= coinchange(a,n,x-a[n-1])+coinchange(a,n-1,x);
    return dp[n][x];
}
int main(){
    rep(i,0,N)
    {
        rep(j,0,N){
            dp[i][j]=-1;
        }
    }
    int n;
    n=5;
    vector<int> a(3);
    a[0]=1,a[1]=2,a[2]=3;
    int x;
    cin>>x;
    cout<<coinchange(a,n,x)<<endl;

return 0;

}
