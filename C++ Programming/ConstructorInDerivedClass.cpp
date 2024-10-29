#include<iostream>
#include<iomanip>
using namespace std;


class base1
{
    int data1;
    public :
    base1(int a)
    {
        data1= a;
        cout<<"base1 constructor called."<<endl;
    }
    void printbase1()
    {
        cout<<"Base 1 : "<<data1<<endl;
    }
};

class base2
{
    int data2;
    public :
    base2(int a)
    {
        data2= a;
        cout<<"base2 constructor called."<<endl;
    }
    void printbase2()
    {
        cout<<"Base 2 : "<<data2<<endl;
    }
};


class derived : public base1,public base2      //this the line where we can change the order of call a constructor
{
    int derived1,derived2;
    public:
    derived (int a,int b,int c,int d) : base1(a),base2(b)
    {
        derived1 = c;
        derived2 = d;
        cout<<"Derived class constructor called."<<endl;   
    } 
    void printderived()
    {
        cout<<"Derived 1 : "<<derived1<<endl;
        cout<<"Derived 2 : "<<derived2<<endl;
    }
};
int main()
{
    derived obj(5,4,3,2);
    obj.printbase1();
    obj.printbase2();
    obj.printderived();
}