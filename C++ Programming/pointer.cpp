#include <iostream>
using namespace std;
int main()
{
    int a =45;
    int *p;
    p=&a;
    int **c=&p;  //------------->>>>>>  POINTER TO POINTER (DOUBLE POINTER)
    cout << "Address of a is :" << p << endl;
    
    cout << "value  of a is :" << *p <<endl;
    cout << "Address of c is :" << c << endl;
    cout << "value at  c is :" << *c << endl;
    return 0;
}