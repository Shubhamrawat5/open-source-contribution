#include <bits/stdc++.h>
#include <vector>
using namespace std;

//#define int long long

int count = 0;

//part:- 1 vector initialization, declaration and traversal
int main()
{
    vector<int> v; //vector of integer

    v.push_back(10);
    v.push_back(100);
    v.push_back(1000);
    v.push_back(10000); //inserting the element
    v.push_back(100000);
    v.push_back(1000000);
    v.push_back(10000000);

    for (int i = 0; i < v.size(); i++)
    {
        // cout << v[i] << endl;    //accessing the vector element by traversing the vector
        cout << v.at(i) << endl; //v.at() will throw the exception if we try to access the element out of bond. so its best way to access the element
        v.at(1) = 99;
        v[2]=65; // it will change the vector element at index 2
    }
    return 0;
}