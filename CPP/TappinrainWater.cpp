#include <bits/stdc++.h>
using namespace std;

int trap(int height[],int size) {
        int n=size;
        int left[n],right[n];
        int i=0;
        left[0]=height[0];
        for(i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        right[n-1]=height[n-1];
        for(i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int ans=0;
        for(i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
int main(){
    int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int N = 12;
    cout<<trap(arr,N);
}