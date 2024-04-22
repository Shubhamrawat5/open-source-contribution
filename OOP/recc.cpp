#include <iostream>
using namespace std;
void reccur(int n){
   if (n==0){
    return ; 
   }
   else{
    cout<< n << endl;
    reccur(n-1);
   }
}
int main()
{

    int n=10;
 reccur(n);
return 0;
}
