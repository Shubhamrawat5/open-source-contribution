#include<iostream>
#include<iomanip>
using namespace std;
class y;
class x
{
    int val1;
    friend void exchange(x &,y &);
    public :
    void setvalue (int value)
    {
        val1=value;
    }
};
class y
{
    int val2;
    friend void exchange(x &,y &);
    public :
    void setvalue(int value)
    {
        val2=value;
    }
};

void exchange(x &e, y &r)
{
    int temp = e.val1;
    e.val1 = r.val2;
    r.val2 = temp;
    cout<<e.val1<<endl;
    cout<<r.val2<<endl;
}

int main()
{
    x a1;
    y b1;
    a1.setvalue(4);
    b1.setvalue(5);
    exchange(a1,b1);
}
