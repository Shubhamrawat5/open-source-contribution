#include<iostream>
#include<iomanip>
using namespace std;
class Employee
{
    private :
    int id;
    int salary;
    public :
    void setdata(void)
    {
        salary=100;
        cout<<"Enter the id : ";
        cin>>id;
    }  
    void getdata(void)
    {
        cout<<"The id of the employee : "<<id<<endl;
    }
};
int main()
{
    Employee fb[4];
    for(int i=0;i<4;i++)
    {
        fb[i].setdata();
        fb[i].getdata();
    }
}