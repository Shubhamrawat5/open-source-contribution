// unique no. is refer to:
// 3,2,3,5,6,5,2
// Here unique no is 6 as all other no. are repeating more than one time

#include <iostream>
using namespace std;
int main()
{
    int n,no;
    // enter no. of elements in list
    cin>>n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>no;
        ans = ans^no;

    }
    cout<<ans<<endl;
    return 0;
}
