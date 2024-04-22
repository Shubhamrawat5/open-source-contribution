#include <iostream>
using namespace std;

class base {

    public:
   virtual void message(){
        cout<<"hello";
    }
};


class derived1 : public base{

    public:
    void message()
    {
         cout<<"good morning\n";
    }
};
class derived2 : public derived1{

    public:
    void message()
    {
         cout<<"good afternoon\n";
    }
};
class derived3 : public derived2{

    public:
    void message()
    {
         cout<<"good evening\n";
    }
};
int main()
{
    base *b1;
    derived1 o1 ,*p1 ;
    derived2 o2 ,*p2;
    derived3 o3;
    b1=&o1;
    b1->message();
    p1=&o2;
    p1->message();
    p2=&o3;
    p2->message();
return 0;
}
