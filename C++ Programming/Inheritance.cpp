#include<iostream>
#include<iomanip>
using namespace std;
class base       //base class
{
    private :
    int id;
    public :
    int salary;
    base(){}
    base(int idno)
    {
         salary=50000;
         id = idno;
    }
};
/*class {(derived-class-name)} : {(visibility-mode)} {(base-class-name)}
when in visibility mode the mode is either public or private then here 
if its public then the base class public member are public in this mode 
if its private then the base class public member are private in this mode 
also the default visibality mode is private*/
//derived class
class derived : public base{
    public :
    int number = 5;
    derived(int amount)
    {
        salary = amount;
    }
};
class Derived : private base 
{
    public :
    Derived(int num){
    int no = 3;
    salary = num;
    }

};
int main()
{
    base s1(1),s2(2);
    cout<<s1.salary<<endl;
    cout<<s2.salary<<endl;
    derived d1(100000),d2(20000);
    cout<<d1.salary<<endl;/*this is only possible when the visiability is set to public*/
    cout<<d2.salary<<endl;
    Derived f1(100000),f2(20000);
   /* cout<<f1.salary; //this is only possible when the class that is inheriated is a default or private
    cout<<f2.salary;*/
    return 0;
}