#include<iostream>
#include<iomanip>
using namespace std;
class Complex;
class calculator 
{
    public :
    int add(int p, int q)
    {
        return (p+q); 
    }
    int sumRealComplex(Complex ,Complex );
    int sumImgComplex(Complex ,Complex );
};
class Complex
{
    int a,b;
    //indivial decleration as a friend
    friend int calculator::sumRealComplex(Complex a1,Complex b1);
    friend int calculator::sumImgComplex(Complex a2,Complex b2);
    //alternative for declearing universally 
    // friend class calculator;
    public :
    void setdata(int x,int y)
    {
        a=x;
        b=y;
    }       
    void printNumber()
    {
        cout<<"Your Complex : "<<a<<" + "<<b<<"i"<<endl;
    }
};
int calculator::sumRealComplex(Complex a1,Complex b1 )
    {
        return (a1.a + b1.a);
    }
    int calculator::sumImgComplex(Complex a2,Complex b2 )
    {
        return (a2.b + b2.b);
    }
int main()
{ 
    Complex k,l,m;
    k.setdata(1,5);
    l.setdata(2,6);
    k.printNumber();
    l.printNumber();
    calculator real ,img;
    int h = real.sumRealComplex(k,l);
    cout<<"The real part sum is : "<<h;
    int g= img.sumImgComplex(k,l);
    cout<<"The imaginary  part sum is : "<<g<<endl;
    return 0;

}