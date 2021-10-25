#include<stdio.h>    
#include<stdlib.h>  
int main(){  
	int a[10],n,i;    
	system ("cls");  
	printf("Enter decimal number: ");    
	scanf("%d",&n);
	int m=n;    
 
	for(i=0;n>0;i++)    
	{    
		a[i]=n%2;    
		n=n/2;    
	}    
 
	printf("%d in Binary is: ",m);    
	for(i=i-1;i>=0;i--)    
	{    
		printf("%d",a[i]);    
	}    
 
	printf("\n");
	return 0;  
}  
