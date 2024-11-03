//inline function is used in small and constant funtions
//not to use inline functions in recurssion & static variables
#include<iostream>
#include<iomanip>
using namespace std;
inline int product(int a,int b)
{
    return a*b;
}
int main()
{
    int x, y;
    cin>>x>>y;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
    cout<<product(x,y)<<endl;
   return 0;
}