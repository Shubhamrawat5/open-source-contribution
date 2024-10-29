#include<iostream>
#include<iostream>
using namespace std;
class simple{
    int data1;
    int data2;
    int data3;
    public :
    simple(int a,int b=6,int c=2)
    {
        data1=a;
        data2=b;
        data3=c;
    }
    void printdata(void);
};
void simple::printdata(void)
{
    cout<<data1<<endl;
    cout<<data2<<endl;
    cout<<data3<<endl;
}
int main()
{
    simple s1(19);
    s1.printdata();
}