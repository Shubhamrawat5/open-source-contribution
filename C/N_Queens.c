//N queens

#include<stdio.h>
#include<math.h>

#define MAX 100

int place(int x[MAX], int r, int c)
{
    int i;
    for(i=1;i<r;i++)
        if(x[i]==c || (abs(x[i]-c)==abs(i-r)))
            return 0;

    return 1;
}

void nqueens( int x[MAX],int r, int n)
{
    int i,c;

    for(c=1;c<=n;c++)
    {
        if(place(x,r,c))
        {
            x[r]=c;
            if(r==n)
            {
                printf("{ ");
                for(i=1;i<=n;i++)
                    printf(" %d ",x[i]);
                printf(" }\n");
            }
            else
                nqueens(x,r+1,n);
        }
    }
}

int main()
{
    int n,i,j;
    int x[MAX];

    printf("Enter the no. of QUEENS : ");
    scanf("%d",&n);

    printf("\nThe solutions are : \n");
    nqueens(x,1,n);
}