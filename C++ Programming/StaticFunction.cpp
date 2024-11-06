//Static  runs runs only one time if its in the loop
#include<iostream>    
#include<iomanip>
using namespace std;
int sol(int x,int y)
{
    static int z=0;
    z=z+1;
    return (x*y)+z;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<sol(a,b)<<endl;
    cout<<sol(a,b)<<endl;
    cout<<sol(a,b)<<endl;
    return 0;
}