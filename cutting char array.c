
#include<stdio.h>
cut(int n, char arr[])
{
    printf("%s\n",arr);
    arr[11-n-1]="\0";
    printf("%s",arr);
}
void main()
{
    char arr[11]="helloworld";
    cut(3, arr);  
} 

