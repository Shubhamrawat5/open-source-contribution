#include <iostream>
using namespace std;

void bubble_sort(int arr[] , int size){
    int sort=0;

     for (int  i = 0; i < size-1 && sort==0; i++)
     {
        cout<<"pass number:"<<i+1<<endl;
        for (int  j = 0 ; j < size-i-1; j++)
        {
            sort=1;
           if (arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            sort=0;
           }
        }
        
     }
     
}
int main()
{
    int arr[10]={1,2,3,4,5,6,7};
    bubble_sort(arr , 7);
    cout<<"sorted array is :\n";
    for (int  i = 0; i < 7; i++)
    {
        cout <<arr[i]<<" ";
    }
    
return 0;
}
