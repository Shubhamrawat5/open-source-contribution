#include<iostream>
#include<iomanip>
using namespace std;

class base{
  protected :
    int a;
    private :
    int b;  
};

/*
protected can be inherited

                          Public derivation        private derivation              protected derivation   
    1.private members     not inherited           not inherited                    not inherited
    2.public members      inherited publically    base members remain private      base members remain protected 
    3.protected           protected               private                          protected 
*/
class derived : protected base 
{
};
int main()
{
    base g;
    derived f;
    //cout<<g.a; this will not work as the variable a is protected in  both derived and base hence can be accessed directly
}