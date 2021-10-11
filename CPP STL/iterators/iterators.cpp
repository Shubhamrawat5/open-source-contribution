#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

/*
begin():- it will give the first position of array element
end():- it goes beyond the last element.. it point the element after  the last element
*/

int main()
{

    vector<int> v = {10, 20, 60, 8, 9, 6, 5, 147, 89};
    //vector<int>::iterator i = v.begin();
    auto i=v.begin();

    for (i; i < v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n"
         << "reverse is : "
         << "\n";
    for (i = v.end() - 1; i >= v.begin(); i--)
    {
        cout << *i << " ";
    }
    
    /*
    // vector<int>::iterator i = v.begin(); can be replaced with auto i=v.begin();

    for (auto i = v.begin(); i < v.end(); i++)  
    {
        cout << *i << " ";
    }

    
    cout << "reverse order : "
         << "\n";
    for (auto i = v.end() - 1; i >= v.begin(); i--)
    {
        cout << *i << " ";
    }
*/
    return 0;
}