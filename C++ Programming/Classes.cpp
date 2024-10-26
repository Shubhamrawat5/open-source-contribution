#include<iostream>
#include<iomanip>
using namespace std;
class Employee
{
    private :
    int a,b,c;

    public :
    int x,y,z ;
    void setData(int a,int b,int c);
    void getData()
    {
        cout<<"The value of a : "<<a<<endl;
        cout<<"The value of b : "<<b<<endl;
        cout<<"The value of c : "<<c<<endl;
    }
};

void Employee::setData(int x,int y,int z)
{
    a=x;
    b=y;
    c=z;
}
int main()
{
    Employee sudarshan;
    sudarshan.setData(1,5,7);
    sudarshan.getData();

    return 0;
}
