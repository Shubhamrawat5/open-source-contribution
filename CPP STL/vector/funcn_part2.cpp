#include <bits/stdc++.h>

using namespace std;

//#define int long long

int count = 0;

int main()
{
    //erase() function in vector
    vector<int> v{10, 20, 35, 65, 89};
    v.erase(v.begin()); //it will erase just one element
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    v.erase(v.begin(), v.end()); // it will erase whole element
    for (int x : v)
    {
        cout << x << " ";
    }

    //clear() function in vector
    vector<int> v2{10, 20, 30, 40, 50};
    v2.clear(); //it will clear all the element of vector
    cout << "The size of the array is : - " << v2.size() << endl;
    if (v2.empty() == 1)
    {
        cout << "vector is empty" << endl;
    }
    else
        cout << "vector is non-empty" << endl;

    //resize function in vector
    cout << "//resize function in vector//" << endl;

    vector<int> v3 = {11, 89, 98, 65, 47, 36, 54};
    cout << "Intially, the size of v3 vector is : " << v3.size() << "\n";
    for (int x : v3)
    {
        cout << x << " ";
    }
    cout << "\n"
         << "after resizing of vector "
         << "\n";
    v3.resize(5);
    for (int x : v3)
    {
        cout << x << " ";
    }
    cout << "\n";
    v3.resize(10);
    for (int x : v3)
    {
        cout << x << " "; //by_default 0 will assign at empty places
    }
    cout << "\n";
    v3.resize(15, 85);
    for (int x : v3)
    {
        cout << x << " "; //by_default 85 will assign at empty places
    }
    return 0;
}