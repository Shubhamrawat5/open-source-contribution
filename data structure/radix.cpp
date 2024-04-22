#include <iostream>
using namespace std;
int max(int arr[], int n)
{
    int m = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}

void radix_sort(int arr[], int n)
{

    static int count[10];
    int arr2[100];
    int mx=max(arr , n);
    int i=1;
    while (mx/i!=0)
    
    {
        for (int j = 0; j < n; j++)
        {
             ++count[(arr[j]/i)%10];
        }
        for (int  j = 1; j<10; j++)
        {
            count[j]=count[j-1]+count[j];
        }
        for (int  j=n-1; j>=0; j--)
        {
            arr2[--count[(arr[j]/i)%10]]=arr[j];
        }

        for (int j=0 ; j < 10; j++)
        {
           count[j]=0;
        }
        for (int  j = 0; j < n; j++)
        {
            arr[j]=arr2[j];
        }
        
        
        
        i=i*10;
        
    }
    
    
}
int main()
{

    int arr[] = {3, 2, 1, 15, 17, 14, 4, 5};
    int n = 8;
    radix_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
