// These algoritms may be applied to most of the stl containers
// we will implement them in vector here
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(2);
    // v.push_back(5);
    v.push_back(4);
    v.push_back(1);
    v.push_back(6);
    v.push_back(3);
    v.push_back(7);

    // binary search - to search if an element is present
    cout << "Check if 6 is present in vector- ";
    cout << binary_search(v.begin(), v.end(), 6) << endl;

    // lower bound:- The element just greater than given element
    cout << "The lower bound for 5 is ";
    cout << lower_bound(v.begin(), v.end(), 5) - v.begin() << endl;

    // upper bound:- The element just smaller than the given element
    cout << "The upper bound for 5 is ";
    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    // maximum of two number
    int a = 8, b = 10;
    cout << "Maximum of " << a << " and " << b << " is " << max(a, b) << endl;

    // minimum of two no.
    cout << "Minimum of " << a << " and " << b << " is " << min(a, b) << endl;

    // swap function to replace the value among themselves
    cout << "Earlier a=" << a << " and b=" << b << endl;
    swap(a, b);
    cout << "Now a=" << a << " and b=" << b << endl;

    // reverse the container
    cout << "Before reversing vector : ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    // calling the reverse function
    reverse(v.begin(), v.end());
    cout << "After reversing vector : ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    // rotate - it will rotate by provided position
    cout << "Before rotating vector : ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    // calling the rotate function
    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "After rotating vector by 1 : ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    // sorting the container
    // it is based on intro sort(quick sort + heap sort + insertion sort)
    cout << "Before sorting vector : ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    // calling the rotate function
    sort(v.begin(), v.end());
    cout << "After sorting vector  : ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}
