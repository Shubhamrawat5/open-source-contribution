#include <stdio.h>

int main()
{
	int n,r, highest=0;
	scanf("%d",&n);

	while(n!=0)
	{
		r=n%10;
		if(r>highest)
			highest=r;
		n=n/10;
	}
	printf("Max digit: %d",highest);

	return 0;
}