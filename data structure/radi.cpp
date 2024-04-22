#include <iostream>
using namespace std;
void radix_sort (int [], int );

int find_max(int arr[] , int size){

    int max=arr[0];
    for (int  i = 0; i < size ; i++)
    {
        if (arr[i]>max){
            max=arr[i];
        }
    }

    return max;
    
}
int main()
{
    int arr[100] , size;
    cout<<"Enter size of an array:";
    cin>> size;
    for (int  i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
     cout<<"array before sort:\n";
    for (int  i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    radix_sort(arr, size);
    cout<<"\narray after sort:\n";
    for (int  i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
return 0;
}

void radix_sort(int arr[] , int l){

    static int counter_arr[10] ;
    int  temp[100];
    int max=find_max(arr , l);
    
    for (int  i = 1 ;  max/i!=0  ; i=i*10)
    {
        for (int  j = 0; j < l; j++)
        {
           counter_arr[ (arr[j]/i)%10]++;
        }

        for (int  j = 1; j < 10; j++)
        {
            counter_arr[j]=counter_arr[j-1]+counter_arr[j];
        }

         for (int  j = l-1;  j >=0 ; j--)
        {
             temp[--counter_arr[(arr[j]/i)%10]]=arr[j];
        }
        for (int  j = 0; j < 10; j++)
        {
            counter_arr[j]=0;

        }
        for (int  j = 0; j <  l; j++)
        {
             arr[j]=temp[j];
        }
        
        

        


    }

    
    
}
