#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 6;
    int arr[n]= {23,10,4,3,20,15};
    int k=2;
    priority_queue<int,vector<int>, greater<int>>min; 
        for(int i=0;i<n;i++){
        min.push(arr[i]); 
        if(min.size()>k){
            min.pop();
        }
    }
    cout<<min.top()<<endl;
    return 0;
}