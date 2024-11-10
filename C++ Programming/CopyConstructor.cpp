#include<iostream>
#include<iomanip>
using namespace std;
class copyC{
    int a=10;
    public :
    copyC()
    {
        a=0;
    }
    copyC(int x)
    {
        a = x; 
    }    
    
    copyC(copyC &obj)
    {
        cout<<"copy constructor called"<<endl;
        a=obj.a;
    }
    void display()
    {
        cout<<a<<endl;
    }
};
int main()
{
    copyC p,q,r(4),z2;
    p.display();
    q.display();
    copyC w(r);//if copy constructor is not there compliler assigns a new copy constructor
    r.display();
    z2=p;// copy constructor will not be called
    copyC l=r;//this copy constructor will be envoked
    l.display();
}