#include <iostream>
using namespace std;
int main()
{

    int arr[]={6,9,1,2,4,7,3};
    int n=7;
    int key,j;
   
    for (int i = 1; i < n ; i++)
    {
        key=arr[i];
        j=i-1;
        while (arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
    

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
return 0;
}
