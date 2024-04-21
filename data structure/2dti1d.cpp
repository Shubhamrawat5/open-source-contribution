#include <iostream>
using namespace std;
int main()
{
    int arr1[100] , arr2[100][100];
    int size , r1,c1;

   cin >> r1 >> c1;
   size=r1*c1;
    
  for ( int  i = 0; i < r1; i++)
    {
        for (int  j = 0; j< c1; j++)
        {
           cin>> arr2[i][j];
        }
       
        
    }

    for ( int  i = 0; i < r1; i++)
    {
        for (int  j = 0; j< c1; j++)
        {
           
           arr1[(c1*i)+j]=arr2[i][j];
        }
       
    }

    for ( int  i = 0; i < size; i++)
    {
       cout << arr1[i]<<" ";
        
    }


    
return 0;
}
