#include<iostream>
#include<iomanip>
using namespace std;
class complex{
    int a;
    int b;

    public :
    complex()
    {
        a=0;
        b=0;
        cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
    }
    
    complex(int x, int y)
    {
        a=x;
        b=y;
        cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
    }
    complex(int x) 
    {
        a=x;
        b=0;
        cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
    }
};

int main()
{
    complex c1(7,9);
    complex c2(5);
    complex(); 
}