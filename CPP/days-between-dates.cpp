#include<stdio.h>
#include<stdlib.h>
long long fac(int x)
{
    long long f=1;
    for(int i=x;i>0;i--)
    {
        f*=i;
    }
    return f;
}
int main()
{
    int n;
    printf("Enter number of rows for which the pascal triangle is to be printed : ");
    scanf("%d",&n);
    int spaces;
    long long temp=0;
    spaces=n;
    for(int i=0;i<n;i++)
    {
        for(int j=spaces;j>0;j--)
        {
            printf("  ");
        }
        int cnt=0;
        for(int j=0;j<=(2*i);j++)
        {
            if(j==0 || j==(2*i))
            {
                printf("1 ");
                cnt++;
            }
            else if(j%2!=0)
            {
                printf("  ");
            }
            else if(j%2==0)
            {
                temp=fac(i)/(fac(i-cnt)*fac(cnt));
                if(temp>=10)
                {
                printf("%Ld",temp);
                }
                else
                {
                    printf("%Ld ",temp);
                }
                cnt++;
            }
        }
        printf("\n");
        spaces--;
    }
    exit(0);
}
