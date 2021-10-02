#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int> arr,int n){
    int sum=0,maximum=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maximum=max(maximum,sum);
        if(sum<0)
            sum=0;
    }
    return maximum;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    int ans1=kadane(v,n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        v[i]=-v[i];
    }
    int ans2=sum+kadane(v,n);
    if(ans1<0)
        cout<<ans1;
    else
        cout<<max(ans1,ans2);
}
