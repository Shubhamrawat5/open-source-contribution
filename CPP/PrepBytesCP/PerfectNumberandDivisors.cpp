//question-https://mycode.prepbytes.com/problems/fundamentals/PRFCTNO

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int num;
    cin>>num;
    int sum=0;
    for(int j=1;j<num;j++)
    {
      if(num%j==0)
      {
        sum=sum+j;
      }
    }
    if(sum==num)
    {
      cout<<"true"<<endl;
    }
    else
    {
      cout<<"false"<<endl;
    }
  }
  return 0;
}