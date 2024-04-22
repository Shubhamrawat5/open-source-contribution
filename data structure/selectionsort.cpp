#include <iostream>
using namespace std;
int main()
{

    int arr[]={1,2,3,4,5,6,7};
    int n=7; 
   
   for (int i = 0; i < n-1 ; i++)
   {
    
           int min=i;
      for (int j = i+1; j < n; j++)
   {
     
      if(arr[min]>=arr[j]){
        int temp=arr[min];
        arr[min]=arr[j];
        arr[j]=temp;
       
      }
   }


   }


    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }


return 0;
}
