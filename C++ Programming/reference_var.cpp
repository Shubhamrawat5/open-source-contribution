#include <iostream>
using namespace std;
//REFERENCE VARIABLE ------> IT IS AN ALTERNATE NAME OF AN EXISTING VARIABLE.
int main()
{
    int a=34;
    int &b=a;
    int &c=b;
    b++;
    cout << a << endl; 
    cout <<b << endl << c ;
    return 0;
}