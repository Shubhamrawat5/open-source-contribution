#include<bits/stdc++.h>
using namespace std;

int decimalToBinary( int n )
{
    int x=1;
    int ans=0;
    while( x <= n )
    x *= 2;
    x/=2;

    while ( x > 0 )
    {
        int lastdigit= n/x;
        n -= lastdigit*x;
        x/=2;
        ans = ans*10 + lastdigit;
    }
    return ans;

}



int32_t main()
{
    int n;
    cin>>n;

    cout<< decimalToBinary(n) << endl;
}