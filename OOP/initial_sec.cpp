#include <iostream>
using namespace std;
class test{
 
 protected:
 int x , y;
 public:
 test(int m , int n): x(m+y), y(n+m){

       cout<<"value of x is:"<<x << endl<<"Value of y is"<< y;
 }




}
;
int main()
{

    test t1(1,45);

return 0;
}
