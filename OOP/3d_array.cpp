#include <iostream>
using namespace std;
int main()
{
   int  count=2;
    int arr[2][2][2];
    for (int i = 0; i < count; i++)
    {
        for (int  j = 0; j < count; j++)
        {
            for (int  k = 0; k < count; k++)
            {
                cin >> arr[i][j][k];
               
            }
            
        }
        
    }

    cout << "Given Array is:\n";
    for (int i = 0; i < count; i++)
    {
        for (int  j = 0; j < count; j++)
        {
            for (int  k = 0; k < count; k++)
            {
                cout <<  arr[i][j][k] ;
                printf("  ");
              
            }

            cout << "\n";
            
        }
        cout <<"\n";
   
        
    }
    
return 0;
}
