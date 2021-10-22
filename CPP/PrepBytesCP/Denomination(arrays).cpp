//Question ~ https://mycode.prepbytes.com/problems/arrays/DENOM
#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      int num,sum,count=0;
      cin>>num;
      while (num!=0)
      {
         if(num>=1000)
         {
            count++;
            sum=num-1000;
            num=sum;
         }
         else if(num>=500)
         {
            count++;
            sum=num-500;
            num=sum;
         }
         else if(num>=100)
         {
            count++;
            sum=num-100;
            num=sum;
         }         
         else if(num>=50)
         {
            count++;
            sum=num-50;
            num=sum;
         }
         else if(num>=20)
         {
            count++;
            sum=num-20;
            num=sum;
         }
         else if(num>=10)
         {
            count++;
            sum=num-10;
            num=sum;
         }
         else if(num>=5)
         {
            count++;
            sum=num-5;
            num=sum;
         }
         else if(num>=2)
         {
            count++;
            sum=num-2;
            num=sum;
         }
         else if(num>=1)
         {
            count++;
            sum=num-1;
            num=sum;
         }
      }

      cout<<count<<endl;
   }
  return 0;
}