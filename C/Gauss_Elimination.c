#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void eliminate(int eq, float arr[][eq+1])
{
    for(int i=0;i<eq-1;i++)
    {
        for(int j=i+1;j<eq;j++)
        {
            float c=arr[j][i]/arr[i][i];
            for(int k=0;k<eq+1;k++)
            {
                arr[j][k]=arr[j][k] - (c*arr[i][k]);           
            }
        }
    }
}

int check(int eq, float arr[eq][eq+1])
{
    int count;
    for(int i=0;i<eq-1;i++)
    {
    for(int j=i+1;j<eq;j++)
    {
        count=1;
        float r1=arr[i][0]/arr[j][0];
        for(int k=1;k<eq+1;k++)
        {
            float r2=arr[i][k]/arr[j][k];
            if(r1==r2)
            {
            count++;
            }
            else if(k!=eq && r1!=r2)
            {
                break;
            }
        }
        if(count==eq)
        {
            return 2;
        }
        else if(count==eq+1)
        {
            return 1;
        }
        else continue;
    }
    }
    return 0;
}

void backsubstitute(int eq , float bs[], float arr[][eq+1])
{
    bs[eq-1]=(arr[eq-1][eq])/arr[eq-1][eq-1];
    for(int i=eq-2;i>=0;i--)
    {
        bs[i]=arr[i][eq];
        for(int j=i+1;j<eq;j++)
        {
            bs[i]=bs[i]-(arr[i][j]*bs[j]);
        }
        bs[i]=bs[i]/arr[i][i];
    }
    printf("Obtained solutions after backsubstitution of given matrix is (Ques 1b): \n");
    for(int i=0;i<eq;i++)
    {
        printf("x%d = %.2f",i+1,bs[i]);
        printf("\n");
    }
    return;
}

int main() //Ques1c
{
    int eq;
    printf("\nEnter the number of variables: ");
    scanf("%d", &eq);

    float arr[eq][eq+1],bs[eq];

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

    eliminate(eq,arr);

    int temp=check(eq,arr);//Ques1d

    if(temp==1)                             
    {
        printf("Infinite Solutions are present for the given set of equations!!!\n"); 
        exit(0);
    }
    else if(temp==2)
    {
        printf("No Solutions are present for the given set of Equations!!!\n"); // If a1/b1=a2/b2=a3/b3......an/bn!=a(n+1)/b(n+1)
        exit(0);                                                                // This is the case when their are no solutions we      
    }                                                                           // check the above equation and if it is satisfied we          
                                                                                // print No Solutions and exit the program.  
    
    printf("Obtained upper triangular matrix is (Ques1a): \n");
    for(int i=0;i<eq;i++)
    {
        for(int j=0;j<eq+1;j++)
        {
            printf("%.2f ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    backsubstitute(eq,bs,arr);

    printf("\n");
    exit(0);
}
