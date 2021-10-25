#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,c,sum=0,Mul=1,temp;
    
    printf("Enter first Number: ");
    scanf("%d",&a);
    printf("Enter last Number: ");
    scanf("%d",&b);
    
    printf("\nAll odd numbers from %d-%d are:\n",a,b);
    
    if (a>b)
    {
    	temp=a;
    	a=b;
    	b=temp;
    }
    for (i=a;i<=b;i++)
    {
        if (i%2==1)
        {
        printf("%d\n",i);
        sum=sum+i;
		Mul=Mul*i;
        }
    }
    
    printf("\n\tTo get Addition of those odd numbers Press 1");
    printf("\n\tTo get Multiplication of those odd numbers Press 2");
    printf("\n\tTo get both Press 3");
    printf("\n\tpress: ");
    scanf("%d",&c);
    
    switch (c)
    {
		case 1:
    	{
    		printf("Addition is: %d\n",sum);
    		break;
    	}
    	
		case 2:
    	{
    		printf("Multiplication is: %d\n",Mul);
    		break;
    	}
    
		case 3:
    	{
    		printf("Addition is: %d\n",sum);
    		printf("Multiplication is: %d\n",Mul);
    		break;
	    }
    return 0;
	}
}
