#include <iostream>
using namespace std;
class test{
    public: 
          int a;
          test &get (int a){
            (*this).a=a;
            return *this;
          }
          void showdata(){
            cout << "value of a is :"<< a << endl;
          }
};
int main()
{
    test t1;
    t1.get(4).showdata();
    t1.showdata();

return 0;
}
