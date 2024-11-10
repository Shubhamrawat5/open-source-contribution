#include<iostream>
#include<iomanip>
using namespace std;

class Base{
    public :
        int var_base=10;
        virtual void display(){
            cout<<"This is base call variable : "<<var_base<<endl;
        }
};
class Derived : public Base{
    public:
        int var_derived=20;
        void display(){
            cout<<"This is derived call variable : "<<var_derived<<endl;
        }
};

int main(){
    Base * base_pt;
    Base base_obj;
    Derived derived_obj;
    base_pt = &derived_obj;
    //base_pt->var_derived=12;  //this will throw an error
    base_pt->var_base=50;
    base_pt->display();

    Derived * derived_pt;
    derived_pt = &derived_obj;
    derived_pt ->var_derived=72;
    derived_pt->display();
}