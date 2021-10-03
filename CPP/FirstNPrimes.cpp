#include <iostream>
using namespace std;

void firstNprimes(int N, int t){
  for (int i=1;i>=1;i++)
	{
		int a=0;
		for (int j=2;j<=i/2;j++)
		{
			if (i%j==0)
			{
				a=1;
			}
		}
		if (a==0 && i!=1)
		{
			printf("%d\n",i);
			t++;
			if (t==N)
			{
				break;
			}
		}
  }
}

int main(){
  int N = 5;
  firstNprimes(N,0);
}
