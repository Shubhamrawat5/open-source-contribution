#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++)
    cin>>b[i];
    int i=0,flag=0;
    for(int k=0;k<n;k++){
        flag=0;
        i=k+1;
    while(b[i]<b[k] && i<n){
        i++;
         
    }
    if(b[i]>b[k] && i<n ){
    cout<<b[i]<<endl;
    flag=1;
         }
        
    if(flag==0)
    cout<<-1<<endl;
   
   
    }
    return 0;
}
