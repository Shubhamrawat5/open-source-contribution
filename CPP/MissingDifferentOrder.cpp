#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter total number of elements ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter number: ";
        cin>>a[i];
    }
    int diff=a[0]-0;
    for(int i=0;i<n;i++){
        if(diff!=a[i]-i){
            cout<<"Missing Element is "<<a[i-1]+1<<endl;
            diff++;
        }
    }

    return 0;
}