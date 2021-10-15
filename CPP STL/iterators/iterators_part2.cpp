#include <bits/stdc++.h>

using namespace std;
/*
i=next(i)= by default it will move one position ahead
i=next(i,4)= in this case it will move 4 position ahead
i=prev(i)= by default it will ove one position back
i=prev(i,3)= if u pass a parameter, then it will move that many position back
advance(i,4)= it is Slightly differnet from next.. next returns the iterartor,
advance modify the same past iterators
*/

int main()
{
    vector<int> v = {10, 20, 30, 40, 50, 60};
    vector<int>::iterator i = v.begin();
    cout << *i << "\n";
    i = next(i,2);
    cout << *i << "\n";
    advance(i, 2);
    cout << *i << "\n";
    i=prev(i);
    cout << *i << "\n";
    i=prev(i,3);
    cout << *i << "\n";

    return 0;
}