#include <iostream>
using namespace std;
class number {

  int num;
  public:
  number (int x){
    num=x;
  }

  number (number *n1){

    num=n1->num;
  }

  void dis(){
    cout<<"Value of number is :"<< num<<endl;
  }


};
int main()
{
    number n1(7);
    n1.dis();
    number n2(&n1);
    n2.dis();
return 0;
}
