//Question - https://mycode.prepbytes.com/problems/fundamentals/PATTERN3

#include <bits/stdc++.h>
using namespace std;

int main()
{
   for (int i = 2; i <= 6; i++)
   {
      for (int j = 1; j < 6; j++)
      {
         if (i > j)
         {
            cout << j;
         }
         else
            cout << " ";
      }
      for (int j = 5; j >= 1; j--)
      {
         if (j < i)
            cout <<j;
         else
            cout << " ";
      }
      cout << endl;
   }
   return 0;
}