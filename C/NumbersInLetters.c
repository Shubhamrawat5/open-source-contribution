#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void num(int m ,char *a[])
{
   int temp;
   if(m>=100)
   {
       temp=m/100;
       printf("%s ",a[temp]);
       printf("%s ",a[30]);
       m=m%100;
   }
   if(m<100 && m>=20)
   {
       temp=m/10;
       printf("%s ",a[20 + temp]);
       m=m%10;
       if(m!=0)
       {
       printf("%s ",a[m]);
       }
       m=0;
   }
   if(m<20 && m>0)
   {
       switch(m)
       {
           case 1: printf("%s ",a[m]); break;
           case 2: printf("%s ",a[m]); break;
           case 3: printf("%s ",a[m]); break;
           case 4: printf("%s ",a[m]); break;
           case 5: printf("%s ",a[m]); break;
           case 6: printf("%s ",a[m]); break;
           case 7: printf("%s ",a[m]); break;
           case 8: printf("%s ",a[m]); break;
           case 9: printf("%s ",a[m]); break;
           case 10: printf("%s ",a[m]); break;
           case 11: printf("%s ",a[m]); break;
           case 12: printf("%s ",a[m]); break;
           case 13: printf("%s ",a[m]); break;
           case 14: printf("%s ",a[m]); break;
           case 15: printf("%s ",a[m]); break;
           case 16: printf("%s ",a[m]); break;
           case 17: printf("%s ",a[m]); break;
           case 18: printf("%s ",a[m]); break;
           case 19: printf("%s ",a[m]); break;
           default: printf("not "); break;
        }
   }
   return;
}
void main()
{
    unsigned long long n;
    long long m;
    char* a[34]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","0","0","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety","hundred","thousand","million","billion"};
    printf("Enter Number : ");
    scanf("%llu",&n);
    if(n==0)
    {
        printf("%s ",a[0]);
    }
    if(1000000000000>n && n>=1000000000)
    {
        m=n/1000000000;
        num(m,a);
        printf("%s ",a[33]);
        n=n-(m*1000000000);
    }
    if(1000000000>n && n>=1000000)
    {
        m=n/1000000;
        num(m,a);
        printf("%s ",a[32]);
        n=n-(m*1000000);
    }
    if(1000000>n && n>=1000)
    {
        m=n/1000;
        num(m,a);
        printf("%s ",a[31]);
        n=n-(m*1000);
    }
    if(1000>n && n>0)
    {
        num(n,a);
    }
    printf("\n");
    exit(0);
}
