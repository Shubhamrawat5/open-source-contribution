//program to sort thes 0's,1's & 2's together.

#include<iostream>
using namespace std;
int sort(int n,int num[])
{
    int a=0;
    for(int j=0;j<n;j++)
    {
    for(int i=0;i<n;i++)
    {

        if(num[i]==a)
        {
        cout<<a;
        }
    }
    a++;
    }
    return 0;
}


int main()
{
    int n,num[100];
    cout<<"Enter the numbet of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    sort(n,num);
}