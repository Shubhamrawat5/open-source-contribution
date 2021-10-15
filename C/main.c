#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,c,sum=0,Mul=1;
    printf("Enter first Number:");
    scanf("%d",&a);
    printf("\nEnter last Number:");
    scanf("%d",&b);
    printf("All odd numbers from %d-%d are:\n",a,b);
    for (i=a;i<=b;i++)
    {
        if (i%2==1)
        {
        printf("%d\n",i);
        }
    }
    printf("\n\tTo get Addition of that numbers Press 1:");
    printf("\n\tTo get Multiplication of that numbers press 2:");
    printf("\n\tpress:");
    scanf("%d",&c);
    switch (c)
    {
    {
case 1:
    {
        for (i=a;i<=b;i++)
        {
            if(i%2==1)
            {
                sum=sum+i;
            }
        }
    printf("Addition is:%d",sum);
    break;
    }
    case 2:
    {
        for(i=a;i<=b;i++)
        {
            if(i%2==1)
            {
                Mul=Mul*i;
            }
        }
    printf("Multiplication is:%d",Mul);
    }
    }
    return 0;
}
}
