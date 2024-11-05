#include<iostream>
#include<iomanip>
using namespace std;
class point
{
    int a,b;
    public :
    point(int x,int y)
    {
        a=x;
        b=y;
     }
     void display(void)
     {
        cout<<"x-Axis : "<<a<<endl<<"y-Axis : "<<b<<endl;
     }
};
int main()
{
    point c1 = point(5,8);
    c1.display();
}