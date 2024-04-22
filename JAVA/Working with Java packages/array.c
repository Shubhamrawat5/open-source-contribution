#include <stdio.h>
#include<stdlib.h>


int main ()
{

    int *arr;
    int n=5;

    arr=(int *)malloc(n*sizeof(int));
    int i=0;
    for (  i=0 ; i<n ; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("given array is:\n");
    for (i = 0; i < n ; i++)
    {
        printf("%d ",*(arr+i));
    }
    
    
return 0;
}
