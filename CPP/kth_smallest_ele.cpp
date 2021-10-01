#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 6;
    int arr[n]= {23,10,4,3,20,15};
    int k=3;
    priority_queue<int>max;
    for(int i=0;i<n;i++){
        max.push(arr[i]); 
        if(max.size()>k){ 
            max.pop();
        }
    }
    cout<<max.top()<<endl;
    return 0;
}