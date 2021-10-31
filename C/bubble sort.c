#include <stdio.h>

 
void main()
{
   
    int i, j, n, temp;
 
    printf("Enter the value of num \n");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements one by one \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Input array is \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("ordered array is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
}
