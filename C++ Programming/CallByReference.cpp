#include<iostream>
#include<iomanip>
using namespace std;
int swap(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}
int swapPointer(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int swapReferenceVar(int &a,int &b)
{
    int temp =a;
    a=b;
    b=temp;
}
int main()
{
    int x,y;
    cout<<"Enter the value for x & y : "<<endl;
    cin>>x>>y;
    swap(x,y);//this won't work
    cout<<"The value for x : "<<x<<endl<<"The value for y : "<<y<<endl;
    swapPointer(&x,&y);
    cout<<"The value for x : "<<x<<endl<<"The value for y : "<<y<<endl;
    swapReferenceVar(x,y);
    cout<<"The value for x : "<<x<<endl<<"The value for y : "<<y<<endl;
}