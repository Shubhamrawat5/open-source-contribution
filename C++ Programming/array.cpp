#include <iostream>
using namespace std;
int main ()
{
    int arr[4];
    for (int i =0 ; i<4 ; i++)
    {
        cin >> arr[i];
    }
    cout << "Given array is :\n";
    int i=0;
    int *ptr=arr;
     do
      {
        cout << *ptr <<endl;
        ptr++;
        i++;
      }while (i<4);
    
return 0;
}