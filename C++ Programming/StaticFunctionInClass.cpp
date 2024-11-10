#include<iostream>
#include<iomanip>
using namespace std;
class Employee
{
    private :
    int id;
    static int count;
    public :
    void setdata(void)
    {
        cout<<"Enter the id:";
        cin>>id;
        count++;
    }
    void getdata()
    {
        cout<<"Your id no. is : "<<id<<endl<<"Your Count is : "<<count<<endl;
    }
    static void getcount()
    {
        cout<<"Current count : "<<count<<endl;
    }  
};
int Employee :: count;
int main()
{
    Employee e1;
    Employee e2;
    Employee e3;

    e1.setdata();
    e1.getdata();
    Employee::getcount();

    e2.setdata();
    e2.getdata();
    Employee::getcount();

    e3.setdata();
    e3.getdata();
    Employee::getcount();
    return 0;
}