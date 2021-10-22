//Question Link- https://mycode.prepbytes.com/problems/fundamentals/BOXTOY

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int box=0;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int t;
    int c;
    cin>>t>>c;
    if(c-t>=2)
    {
      box++;
    }
  }
  cout<<box;
  
  return 0;
}