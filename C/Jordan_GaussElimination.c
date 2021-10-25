#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void jordaneliminate(int eq, float arr[][eq+1])
{
    for(int i=0;i<eq;i++)
    {
        for(int j=0;j<=eq;j++)
        {
            float c=arr[j][i];
            for(int k=0;k<eq+1;k++)
            {
                if(j!=i)
                {
                    arr[j][k]=(arr[i][i]*arr[j][k]) - (c*arr[i][k]);
                }           
            }
        }
    }
     
    printf("Obtained Diagonal matrix is : \n");
    for(int i=0;i<eq;i++)
    {
        for(int j=0;j<eq+1;j++)
        {
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf( "\nSolutions:" );
    float temp;
    for(int i=0;i<eq;i++)
    {
        temp=arr[i][eq]/arr[i][i];
        printf("\nTHE VALUE OF x%d IS %.2f\n",i+1,temp);
    }
    return;

}

int main()
{
    int eq;
    printf("\nEnter the number of variables: ");
    scanf("%d", &eq);

    float arr[eq][eq+1];

    for (int i=0;i<eq;i++)
    {
        printf("\nFor equation %d:\n", i+1);
 
        for (int j=0;j<eq;j++)
        {
            printf("Enter the coefficient of  x%d: ", j+1);
            scanf("%f", &arr[i][j]);
        }
 
        printf("Enter the constant: ");
        scanf("%f", &arr[i][eq]);
    }

    printf("\nGiven augmented matrix is : \n");
    for(int i=0;i<eq;i++)
    {
        for(int j=0;j<eq+1;j++)
        {
            printf("%.2f ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    jordaneliminate(eq,arr);

    exit(0);
}
