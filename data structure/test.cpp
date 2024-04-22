#include <iostream>
using namespace std;

class test{

    int x,y;
    void sum(int a , int b){
        cout<<"sum is :"<<a+b;
    }
    public:
       void call(int m , int n){
        x=m;
        y=n;

        sum(x,y);
       }
    
    };
int main()
{
    test t1;
    t1.call(6,7);
return 0;
}
