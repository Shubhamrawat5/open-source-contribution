#include <iostream>
using namespace std;
int area (int l , int b)
{
    return l*b;
}

int area(int rad)
{
    return 3.24*rad*rad;
}

int main()
{
    //Function overloading -----it means two or more than two function can have the same name with different parameter
    //polymorphism ----------means having many  form.
    int l,b,r;
    cin >>  l >> b >> r;

    cout << "Area of rectangle :" << area(l,b) << endl;
    cout << "Area of circle is :" << area(r);

    return 0;
}