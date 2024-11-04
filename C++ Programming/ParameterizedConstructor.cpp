#include<iostream>
#include<iomanip>
using namespace std;
class complex
{
    int a,b;
    public :
    complex(int ,int);      //parameterized constructor
    void p(void)
    {
        cout<<a<<"+"<<b<<"i"<<endl;
    }
};
complex::complex(int x,int y) 
{
    a=x;
    b=y;
}
int main()
{
    //implicit call
    complex c1(1,2);
    c1.p();
    //explicit call
    complex c2 = complex(5,6);
    c2.p();
}