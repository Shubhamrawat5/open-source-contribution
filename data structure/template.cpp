#include <iostream>
using namespace std;

template <class T>T  add (T &a , T &b){


    T sum;
    sum =a+b;
    cout<<"sum is:"<<sum<<endl;
}
int main()
{

    int a=5 , b=6;
    add(a,b);
return 0;
}
