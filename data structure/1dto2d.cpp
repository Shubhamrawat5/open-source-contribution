#include <iostream>
using namespace std;
int main()
{
    int arr1[100] , arr2[100][100];
    int size , r1,c1;

    cin>>size;
    for (int  i = 0; i < size; i++)
    {
       cin >> arr1[i];
    }

    cin>> r1 >> c1;

    if (size > (r1*c1)){
        cout<<"cannot be convert";

    }
    else {
          for ( int i = 0; i < r1; i++)
    {
        for (int  j = 0; j< c1; j++)
        {
            arr2[i][j]=arr1[(c1*i)+j];
        }
       
        
    }
    }
    
  for ( int  i = 0; i < r1; i++)
    {
        for (int  j = 0; j< c1; j++)
        {
            cout<< arr2[i][j]<<" ";
        }
        cout<<endl;
        
    }
return 0;
}
