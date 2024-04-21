#include <iostream>
using namespace std;

void merge (int arr[] ,int low , int mid  , int high){
    
      
      int i=low  , j=mid+1 ;
      int arr2[100];
      int k=low;
      while (i<=mid && j <=high){
         if (arr[i]<arr[j]){
             arr2[k]=arr[i];
             i++;
             k++;
         }
         else {
            arr2[k]=arr[j];
            j++;
            k++;
         }

      }

         while (i<= mid){
            arr2[k]=arr[i];
            i++;
            k++;
         }
         while (j<=high){
            arr2[k]=arr[j];
            j++;
            k++;

         }

      
    for (int  i = low; i <= high ; i++)
    {
        arr[i]=arr2[i];
    }
    
}

void merge_sort(int arr[] , int low , int high){

if (low < high){
    int mid=(low+high)/2;
    merge_sort(arr, low , mid);
    merge_sort(arr , mid+1 , high);
    merge(arr , low , mid , high);
}

}
int main()
{

    int arr[]={4,1,3,2,6,5};
    int n=6;
    int low=0 , high=n-1 ;
    merge_sort(arr , 0 , 5) ;
    for (int i = 0; i < n; i++)

    {
          /* code */
          cout<<arr[i]<<" ";
    }
    
return 0;
}
