#include<stdio.h>  
int partition(int a[], int low, int high)   
{  
    int pivot = a[high];     int i = (low - 1);  
    int j;   
    for ( j = low; j <= high - 1; j++)   
    {  
        if (a[j] < pivot)   
  	    {  
            i++;      
            int temp = a[i];  
            a[i] = a[j];             
            a[j] = temp;  
        }  
    }      
    int temp = a[i + 1];
    a[i + 1] = a[high];     
    a[high] = temp;  
    return (i + 1);  
}  

void quickSort(int a[], int low, int high)   
{  
    if (low < high)   
    {  
        int pi = partition(a, low, high);         
        quickSort(a, low, pi - 1);         
        quickSort(a, pi + 1, high);  
    }  
}  
int main()   
{
     int n;
     int i;  
    printf("Enter the number of elements");  
    scanf("%d", &n);  
  
    int a[n];  
    printf("Enter %d elements\n", n);  
    for ( i = 0; i < n; i++)   
 {  
        scanf("%d", &a[i]);  
    }  
    printf("Original aay ");  
    for (i = 0; i < n; i++)   
 {  
        printf("%d ", a[i]);  
    }  
    quickSort(a, 0, n - 1);     
printf("\nSorted aay ");     for (i = 0; i < n; i++)   
 {  
        printf("%d ", a[i]);  
    }  
  
    return 0;  
}