#include<iostream>
#include<iomanip>
using namespace std;

int fact(int n)
{
    if(n<=1)
    {
        return n;
    }
    else{
        return n*fact(n-1);
    }
}

int fib(int n);
int main()
{
    int x;
    cout<<"Enter the number : ";
    cin>>x;
    cout<<"Factorial of "<<x<<" is "<<fact(x);
    int pos;
    cout<<"Enter the position : ";
    cin>>pos;
    cout<<endl<<"Fibonacci of "<<pos<<" is "<<fib(pos);
    return 0;
}
int fib(int n)
{
    if(n<2)
    {
        return n;
    }
    return fib(n-1)+fib(n-2);
}