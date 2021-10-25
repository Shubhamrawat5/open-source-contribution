//Question-https://mycode.prepbytes.com/problems/fundamentals/RVSREUM

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int num;
  cin>>num;
  int reverse=0;
  while(num!=0)
  {
    reverse=num%10;
    num=num/10;
    cout<<reverse;
  }
  return 0;
}