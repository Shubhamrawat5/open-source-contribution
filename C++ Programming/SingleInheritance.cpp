#include<iostream>
#include<iomanip>
using namespace std;
class base{
    int num1;
    public :
    int num2;
    int sum;
    int getnum1();
    int getnum2();
    int  process1();
};

int base ::getnum1()
{
    cin>>num1;
    return num1;
}

int base :: getnum2()
{
    cin>>num2;
    return num2;
}
int base::process1()
{
    int sum = num1+num2;
    return sum;
}

class derived : public base
{
    public:
    int num3;
    int product;
    int getnum3();
    int process2();  
    void display(void);
};
int derived:: getnum3()
{
    cin>>num3;
    return num3;
}
int derived :: process2()
{
    int product = num3 *process1() ;
    return product;
}
void derived :: display()
{
    cout<<"Number 1 : "<<getnum1<<endl;
    cout<<"Number 2 : "<<num2<<endl;
    cout<<"Number 3 : "<<num3<<endl;
    cout<<"First process : "<<sum<<endl;
    cout<<"Second process : "<<product<<endl;
}
int main()
{
    derived obj;
    obj.getnum1();
    obj.getnum2();
    obj.getnum3();
    obj.process1();
    obj.process2();
    obj.display();
    return 0;
}