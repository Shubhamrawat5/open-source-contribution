#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int originaln=n;
    while(n>0)
    {
        int ld= n%10;
        sum+= pow(ld,3);
        n=n/10;
        cout<<sum<<endl;
        cout<<n<<endl;
    }
    
       if(sum==originaln)
       {
           cout<<"Armstrong No.";
       }
       else
       {
           cout<<" Not Armstrong No.";
       }
       return 0;
}

    
