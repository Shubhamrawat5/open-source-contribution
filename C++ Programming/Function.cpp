#include<iostream>
#include<iomanip>
using namespace std;
int sum(int a,int b)
{
    int c = a+b;
    cout<<"Your Sum : "<<c<<endl ;
}

int difference(int a,int b);
void p(void );
int main()
{
    int num1,num2;
    cout<<"Enter the 2 number : ";
    cin>>num1>>num2;
    sum(num1,num2);
    difference(num1,num2);
    p();
}   
int difference(int a , int b)
{
    int c;
    c=a-b;
    cout<<"Your difference : "<<c;
}

void p(void)
{
    cout<<endl<<"Hello World";
}