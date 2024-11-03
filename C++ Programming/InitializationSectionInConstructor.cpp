#include<iostream>
using namespace std;
class Test{
    int a;
    int b;
    public :
    // Test(int i,int j) : a(i) , b(j)
    // Test(int i,int j) : b(j) , a(i)
    // Test(int i,int j) : a(j) , b(i)
    // Test(int i ,int j) : a(b+i) , b(j) ---->>this will give no error but in output returns garbage value
    // Test(int i , int  j) : a(i),b(a+j)
    Test(int i, int  j)
    {
        a=i;
        b=j;
        cout<<"Constructor called"<<endl;
        cout<<"Value of a : "<<a<<endl;
        cout<<"Value of b : "<<b<<endl;
    }
};

int main()
{
    Test object(10,20);
}