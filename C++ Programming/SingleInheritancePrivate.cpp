//when we declare the visibality as private then the variables in the base class cant be called in  main function directly by using the derived class object but we can call them in the function of the derived class
#include<iostream>
#include<iomanip>
using namespace std;
class base
{
    int num1;
    public :
    int num2;
    void setdata();
    int getdata1();
    int getdata2();
};

void base :: setdata(void)
{
    num1 = 10;
    num2 = 20;
}

int base:: getdata1()
{
    return num1;
}
int base:: getdata2()
{
    return num2;
}
class derived :private base
{
    int num3;
    public :
    void process();
    void display();
};
void derived::process()
{
     setdata();

    num3 = num2*getdata1();
}
void derived :: display()
{
    cout<<"1st Number : "<<getdata1()<<endl;
    cout<<"2nd Number : "<<num2<<endl;
    cout<<"3rd Number : "<<num3<<endl;    
}
int main()
{
    derived d;
    // d.setdata();
    // d.getdata1();
    // d.getdata2();
    d.process();
    d.display();
}