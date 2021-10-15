#include <bits/stdc++.h>
//#include <algorithm>

using namespace std;

//#define int long long

int main()
{
    int arr[] = {10, 222, 30, 4, 99, 55, 144, 551};
    int size = sizeof arr / sizeof arr[0];
    cout << "size is " << size << endl;
    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout << arr[i] << " "
             << "\n";
    }
    int it= lower_bound(arr, arr + size, 55)-arr;
    
    if (arr[it]==55)
    {
        cout << "present at "<<it;
    }
    else
        cout << "not present";

    return 0;
}
