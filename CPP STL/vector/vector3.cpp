#include <bits/stdc++.h>

using namespace std;

//#define int long long

int count = 0;

//part:-3 vector initialization, declaration and traversal
int main()
{
    int n = 3, x = 10; //n is the size of vector, and x is the element. so the vector will be :- {10,10,10}
    vector<int> v(n, x);
    for (auto it = v.begin(); it < v.end(); it++)
    {
        cout << *it << " " << endl;
    }
    return 0;
}