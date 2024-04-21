#include <iostream>
using namespace std;

class number {
   public:
int x, y;

void input(int a ,int b){
   x=a;
   y=b;
}
number operation(number n1 , number n2){
   number n3;
   n3.x=n1.x+n2.x;
   n3.y=n1.y+n2.y;
   return n3;
}

};
int main()
{

   number n1, n2 , n3;
   n1.input(1,2);
   n2.input(2,3);
   n3=n2.operation(n1,n2);
   cout <<n3.x << endl << n3.y;
return 0;
}
