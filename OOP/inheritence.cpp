#include <iostream>
using namespace std;

class num{
    public:
    int a ;
    num (int b){
        a=b;
    }
    num(){};
    void show()
    {
        cout<< a <<endl;
    }

};

class test :public num{
    public:
    test(int c){

        a=c;
    }
  
    void get()
    {
        cout<< a <<endl;
    }
};
int main()
{
    num n1 (34);
    n1.show();
    test t1(2);
    t1.get();
 cout <<  n1.a << endl;
  cout <<  t1.a << endl;
return 0;
}
