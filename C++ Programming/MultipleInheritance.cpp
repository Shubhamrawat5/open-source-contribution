#include<iostream>
#include<iomanip>
using namespace std;
class base1
{
    protected :
    int base1int;
    public :
    void setbase1int(int a)
    {
        base1int=a;
    }
};

class base2 
{
    protected :
    int base2int;
    public :
    void setbase2int(int a)
    {
        base2int=a;
    }
};

class derived : public base1 ,public base2{
    public : 
    void show() {
        cout<<"The value of base 1 : "<<base1int<<endl;
        cout<<"The value of base 2 : "<<base2int<<endl;
        cout<<"Sum : "<<base1int + base2int;
    }
};
int main()
{
    derived obj ;
    obj.setbase1int(10);
    obj.setbase2int(20);
    obj.show();
}