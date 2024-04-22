#include <iostream>
using namespace std;

template <class M>  M add ( M &a , M &b){

    a=7;
    return a+b;
}
int main()
{

int res;
int a=1,b=2;
res=add(a,b);
cout<< res;
return 0;
}
