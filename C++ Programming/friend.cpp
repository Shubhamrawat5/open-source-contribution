#include <iostream>
using namespace std;

class B;
class C;
class D;

class A
{
    int a;

public:
    A(int b)
    {
        a = b;
    }
    friend void display(A, B , C, D);
};

class B
{
    int b, sum;

public:
    B(int c)
    {
        b = c;
    }
    friend void display(A, B , C , D);
};

class C{

    int c ;
    public:
    C(int m){
        c=m;
    }
    friend void display(A, B , C , D);

};

class D{

    int d ;
    public:
    D(int m){
        d=m;
    }
    friend void display(A, B , C , D);

};



void display(A a1, B b1, C c1 , D d1)
{
    int sum1 , sum2;
    sum1 = a1.a + b1.b;
    sum2=c1.c+d1.d;
    cout << "sum  of first two numbers is:" << sum1 << endl;
    cout << "sum  of fnext two numbers is:" << sum2 << endl;
}

int main()
{

    A a1(2);
    B b1(3);
    C c1(5);
    D d1(4);
    display(a1, b1 , c1 , d1);

    return 0;
}