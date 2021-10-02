#include<bits/stdc++.h>
using namespace std;
int main()

{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i=i+2)
    {
        if(a[i+1]>a[i])
        {
            swap(a[i],a[i+1]);
            cout<<a[i]<<" "<<a[i+1]<<" ";
        } 
        else
        {
            cout<<a[i]<<" ";
        }
    
    
        

    }
    
    return 0;
}