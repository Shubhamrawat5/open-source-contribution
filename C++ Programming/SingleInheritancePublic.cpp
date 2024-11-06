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
class derived :public base
{
    int num3;
    public :
    void process();
    void display();
};
void derived::process()
{
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
    d.setdata();
    d.process();
    d.display();
}