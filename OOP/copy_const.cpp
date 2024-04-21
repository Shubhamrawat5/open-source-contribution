#include <iostream>
using namespace std;
class num{
      
      int a;
      public:
      num (){
        a=0;

      }
      num (int z ){
        a=z;
      }
      num (num &x){
        a=x.a;
        cout<< "copy constructor is called....."<< endl;
      }
      void show (){
        cout << "Value of num is :"<< a << endl;
      }
};
int main()
{

    num n1 , n2(43) , n3(n2) ;
    n1.show();
    n2.show();
    n3.show();
    num n4=n3;
    n4.show();
    
return 0;
}
