/*
PROBLEM STATEMENT
-------------------------------------------------------------------------------------
A Gray code is a list of all 2n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

Your task is to create a Gray code for a given length n.


Input
-----------------------------------------------------------------------
The only input line has an integer n.

Output
------------------------------------------------------------------------------------------
Print 2n lines that describe the Gray code. You can print any valid solution.

Constraints
------------------------------------------------------------------------------------------------------
1≤n≤16
Example
--------------------------------------------------------------------------------------------------------------
Input:
--------------------------------------------------------------------------------------------
2

Output:
----------------------------------------------------------------------------------
00
01
11
10



*/



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n;
    cin >> n;
 
    vector<string> v = {""};
    if (n == 0)
        exit(0);
 
    vector<string> temp;
 
    FOR(i, 1, n + 1)
    {
       
 
        vector<string> temp(v);
        reverse(temp.begin(), temp.end());
 
        v.insert(v.end(), temp.begin(), temp.end());
 
        FOR(j, 0, pow(2, i))
        {
            if (j < pow(2, i) / 2)
            {
                v[j] = "0" + v[j];
            }
            else
            {
                v[j] = "1" + v[j];
            }
        }
    }
    for (string i : v)
        cout << i << "\n";
    return 0;
}
