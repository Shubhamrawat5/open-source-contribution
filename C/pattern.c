#include <stdio.h>  
  
int main()  
{  
    int n,m;  
    printf("Enter the number of rows");  
    scanf("%d",&n);  
    m=n;  
   for(int i=1;i<=n;i++)  
   {  
       for(int j=1;j<i;j++)  
       {  
           printf(" ");  
       }  
       for(int k=1;k<=m;k++)  
       {  
           printf("*");  
       }  
       m--;  
     
      printf("\n");  
    }  
    return 0;  
}