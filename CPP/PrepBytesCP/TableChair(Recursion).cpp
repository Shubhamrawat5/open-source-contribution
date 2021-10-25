//Question-https://mycode.prepbytes.com/problems/fundamentals/TABLECHAIR
#include <bits/stdc++.h>
using namespace std;
long long M,R1,R2,R3;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin>>M>>R1>>R2>>R3;
    M%=4;
    if(M==0)
      cout<<0<<endl;
    if(M==3)
      cout<<min(R1,min(R2+R3,R3+R3+R3))<<endl;
    if(M==2)
      cout<<min(R2,min(R1,R3)*2)<<endl;
    if(M==1)
      cout<<min(R3,min(R1+R2,R1+R1+R1))<<endl;
  }
  
  return 0;
}