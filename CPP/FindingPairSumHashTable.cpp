#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int a[n];
    int max=-99999999;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max){
            max=a[i];
        }
    }
    
    int k;
    cout<<"Enter value of k ";
    cin>>k;
    
    int hash[k]={0};

    for(int i=0;i<n;i++){
        ++hash[a[i]];
        int temp=hash[k-a[i]];
         if(temp>0){
             cout<<a[i]<<"+"<<k-a[i]<<"="<<k<<endl;
            }
    }
        
    return 0;
}