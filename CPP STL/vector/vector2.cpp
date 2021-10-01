#include <bits/stdc++.h>

using namespace std;

//#define int long long

int count = 0;
//part:-2 vector initialization, declaration and traversal
int main()
{
    vector<int> v{11, 22, 33, 44, 55, 66}; //vector created as well as intialized
    for (int x : v)
    {
        cout << x << "  "; //traversal
    }
    /*
    for (int x : v)
    {
        x = 6;  it will not change the vector element cozz it just a copy of vector element
    }
    */
    for (int &x : v)
    {
        x = 9; //it will change the vector element cozz we using refernce
    }
    for (int x : v)
    {
        cout << x << "  "; //traversal
    }
    return 0;
}