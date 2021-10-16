#include <bits/stdc++.h>
// #include <utility>

// #include <iostream>

using namespace std;

//#define int long long

pair<int, int> p1(10, 20), p2(10, 20), p4;

int main()
{
    //type:-1
    pair<int, char> PAIR1;
    PAIR1.first = 100;
    PAIR1.second = 'G';
    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
    //type:-2
    pair<string, double> PAIR2("shubham", 1.23);
    cout << PAIR2.first << " ";
    cout << PAIR2.second << endl;
    //type:-3
    pair<string, double> PAIR3;
    PAIR3 = make_pair("my dad is Best", 4.56);
    cout << PAIR3.first << " ";
    cout << PAIR3.second << endl;
    //type:-4
    pair<int, int> PAIR4;
    PAIR4 = {100, 220};
    cout << PAIR4.first << " ";
    cout << PAIR4.second << endl;
    cout << "//output of comparison operator//" << endl;

    cout
        << p1.first << "  " << p1.second << endl;
    cout << p2.first << "  " << p2.second << endl;
    cout << p4.first << " " << p4.second << endl;
    cout << (p1 == p2) << endl;
    cout << (p1 != p2) << endl;
    cout << (p1 < p2) << endl;
    cout << (p1 > p2) << endl;
    cout << (p1 <= p2) << endl;
    cout << (p1 >= p2) << endl;

    return 0;
}