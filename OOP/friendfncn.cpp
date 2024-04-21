#include <iostream>
using namespace std;

class test{
 int a ,b;
 public:
 void set(void){
    cin>>a>>b;
     }
   friend test show ( );
   void dis(void){
    cout << "Value is :" << a << b<<endl;
   }

};

test show ( void ){

    test t3;
    t3.set();
    return t3;

    // cout << "Value of member first is:"<<t1.a<<endl;
    // cout << "Value of member second is:"<<t1.b<<endl;
    return t3;
}
int main()
   
{

    test t1 , t2 , ext;
    t1.set();
    t1.dis();
    t2.set();
    t2.dis();
    ext=show();
    ext.dis();

    
    

return 0;
}
