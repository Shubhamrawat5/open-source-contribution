#include <bits/stdc++.h>

using namespace std;

template <typename t>
t arrmax(t arr[], t n)
{
    t res = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > res)
        {
            res = arr[i];
        }
    }
    return res;
}
int main()
{
    int arr[] = {10, 20, 30, 100, 50, 11};
    int x = sizeof(arr) / sizeof(arr[0]);
    cout << arrmax<int>(arr, x)<<endl;
    char arr2[] = {'s', 'h', 'A', 'Z', 'z', 'M'};
    //int x = sizeof(arr2) / sizeof(arr2[0]);
    cout << arrmax<char>(arr2, 6)<<endl;
    float arr1[]={1.2,3.8,9.5,1.3,4.6};
     int y=sizeof(arr1) / sizeof(arr1[0]);
    cout << arrmax<float>(arr1, y);
    return 0;
}