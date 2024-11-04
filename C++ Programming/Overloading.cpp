#include<iostream>
#include<iomanip>
using namespace std;
int sum(int a,int b)
{
    return a+b;
}
int sum(int a , int b, int c)
{
    return a+b+c;
}
int main()
{
    int x=1,y=2,z=3;
    cout<<sum(x,y)<<endl;
    cout<<sum(x,y,z);
}