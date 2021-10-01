#include <bits/stdc++.h>

using namespace std;

//function template with some limit

template <class t, int limit>
t arrmax(t arr[], t n)
{
    if (n > limit)
    {
        cout << "limit exceeded";
    }
    else
    {
        int res = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > res)
            {
                res = arr[i];
            }
        }
        return res;
    }
    return 0;
}
int main()
{
    int arr[] = {10, 20, 30, 100, 50, 11};
    int x = sizeof(arr) / sizeof(arr[0]);
    cout << arrmax<int, 50>(arr, x) << endl;

    return 0;
}