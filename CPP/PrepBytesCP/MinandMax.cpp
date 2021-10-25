//Question - https://mycode.prepbytes.com/problems/arrays/MINMAX1
#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--)
   {
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
      {
         cin>>arr[i];
      }
      int minele=INT_MAX;
      int maxele=0;
      for(int i=0;i<n;i++)
      {
         minele=min(minele,arr[i]);
      }
      cout<<minele<<" ";
      for(int i=0;i<n;i++)
      {
         maxele=max(maxele,arr[i]);
      }
      cout<<maxele<<endl;
      

   }
  return 0;
}