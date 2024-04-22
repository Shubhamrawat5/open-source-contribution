#include <iostream>
using namespace std;
int partition(int arr[] , int low , int high){
    int i, j , temp;
    i=low+1;
    j=high;
    int piviot=arr[low];
    do{
        while (arr[i]<=piviot){
            i++;

        }
        while (arr[j]>piviot){

            j--;
        }
        if (i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while (i<j);
temp=arr[low];
arr[low]=arr[j];
arr[j]=temp;
return j;
}
void quicksort(int arr[] , int low ,int high){
 if (low < high){
    int piviot=partition(arr, low , high);
    quicksort(arr, low , piviot-1);
    quicksort(arr, piviot+1 , high);

}
}
int main()
{
    // int arr[]={19,9,14,24,29,27};
    int arr[]={1,2,3,4,5,6};       //{24,27,25}
    int n=6;
   quicksort(arr , 0 , n-1);
   for (int  i = 0; i < n; i++)
   {
     cout << arr[i]<< " "; 
   }
    
return 0;
}
