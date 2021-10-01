#include <bits/stdc++.h>
using namespace std;
long long findMinDiff(long long a[], long long n, long long m){
        //1.sort the array
        sort(a,a+n);
        //2.find the min difference
        long long mi=INT_MAX,diff;
        for(int i=0;i+m-1<n;i++){
            diff=a[i+m-1]-a[i];
            mi=min(mi,diff);
        }
        //3.return the appropiate result
        return mi;
    }   
int main(){
    long long arr[]={3, 4, 1, 9, 56, 7, 9, 12};
    long long N = 8, M = 5;
    cout<<findMinDiff(arr,N,M);
}