#include <iostream>
using namespace std;
class number {
    
int x;
public:
void input(int a){
    x=a;
}

number  operator+( number n1 ){
    int sum ;
    number n3;
   
    n3.x=n1.x+x;
  
    return n3;
}

void dis (){

    cout<<"\nValue of sum is :"<< x<<endl;
}


};
int main()
{

    number n1 , n2;
    n1.input(4);
    n2.input(8);
   number n3= n1+n2;
   n3.dis();
   
return 0;
}
