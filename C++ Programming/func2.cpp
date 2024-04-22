#include <iostream>
using namespace std;
/* Inline functions    ->   i.)when we need to call our function multiple times in our program then we use  inline function.
                            ii.)It reduce the time complexity of a program.
                            iii.)we should use then only if we need to deal with simple function.Otherwise it will increase the
                                 space complexity of a program.
*/ 
 int add (int , int); 
inline int  add(int a , int b=45)     //default arguement are the arguements that are provide by the function by default when user does not provide it.
{                                     // default arugement should be write in last.
    return 4+a+b;
}
int main ()
{
    int a;
    cin >> a ;
    cout << add(a) << endl;
    cout << add(a) << endl;
    cout << add(a) << endl;
    cout << add(a,78) << endl;
    cout << add(a) << endl;
    cout << add(a) << endl;
return 0;
}