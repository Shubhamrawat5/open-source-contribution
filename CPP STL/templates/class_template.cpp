//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename t>
struct cordinate
{
    t x, y;
    cordinate(t i, t j) //constructor
    {
        x = i;
        y = j;
    }
    t getfirst()
    {
        return x;
    }

    t getsecond()
    {
        return y;
    }
};

//template <typename t>
// pair<t>::getfirst
// {
//     return x;
// }
int main()
{
    cordinate<int> p1(10, 20), p2(99, 89);
    cout << p1.getfirst() << " " << p1.getsecond() << endl;
    cout << p2.getfirst() << " " << p2.getsecond() << endl;
    cordinate<float> p3(10.4, 11.6);
    cout << p3.getfirst() << " " << p3.getsecond() << endl;

    return 0;
}