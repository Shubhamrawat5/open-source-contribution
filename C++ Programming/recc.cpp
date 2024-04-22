#include <iostream>
using namespace std;
int fabo(int num);
int fabo(int num)
{
   if (num == 1)
   {
    return 0;
   }
   else if (num ==2)
   {
    return 1;
   }
   else
   return fabo(num-1)+fabo(num-2);
}
int main()
{
    int num;
    cin >> num;
    cout << fabo(num);
    // for (int i=1 ; i <= num ; i++)
    // {
    //     cout << "f(" << i << "):" << fabo(i) << endl;
    // }
    return 0;
}