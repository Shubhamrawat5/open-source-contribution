#include<iostream>
#include<iomanip>
using namespace std;
class Complex
{
    int a,b;

    public :
    void setdata(int x,int y)
    {
        a=x;
        b=y;
    }       
    void setDataBySum(Complex a1,Complex b1)
    {
        a= a1.a + b1.a;
        b= a1.b + b1.b;
    }

    void printNumber()
    {
        cout<<"Your Complex : "<<a<<" + "<<b<<"i"<<endl;
    }
};
int main()
{
    Complex c1,c2,c3;
    c1.setdata(1,3);
    c1.printNumber();

    c2.setdata(5,6);
    c2.printNumber();

    c3.setDataBySum(c1,c2);
    c3.printNumber();
    return 0;
}