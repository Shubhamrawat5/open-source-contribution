#include <stdio.h>
int main(void)
{
 int n;
 printf("Enter number of rows and columns");
 scanf("%d", &n);
 for(int i=n;i>0;i--)
 {
 for(int j=1;j<i;j++)
 {
 printf(" ");
 }
 for(int k=i;k<=n;k++)
 {
 printf("%d", k);
 }
 printf("\n");
 }
 return 0;
}
