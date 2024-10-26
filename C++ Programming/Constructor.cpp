#include<iostream>
#include<iomanip>
using namespace std;
class complex{
    int a,b;
    public :
    complex(void); //constructor is declared ---default constructor
                    //must be declared in public section of class
    void p()
    {
        cout<<"complex number : "<<a<<"+"<<b<<"i"<<endl;
    }   
};

complex::complex(void)
{
    a=5;
    b=6;
}
int main()
{
    complex e; //constructor is directly invocked when object is created 
                //can't return value and no return type
    e.p();      //can't refer to address
}