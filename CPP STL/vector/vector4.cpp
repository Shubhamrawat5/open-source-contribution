#include <bits/stdc++.h>

using namespace std;

//#define int long long

int count = 0;

int main()
{
    int arr[] = {10, 5, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    //vector<int>::iterator it = v.begin();
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " " << endl;
    }
    return 0;
}