#include <iostream>
#include <vector>

using namespace std;

//#define int long long
/*
vector function

1. pop_back();
2. front();
3. back();
4. resize(); 
5. insert();
6. empty();
7. clear();
8. erase();
*/

int count = 0;

int main()
{
    vector<int> v{10, 20, 30, 4, 5, 440};
    v.pop_back();
    //v.at(0) = 0; or
    //v[0]=77; or
    //v.front() = 11;
    v.front() = 11;
    v.back() = 11;
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << "front elelment of vector is : - " << v.front() << endl;
    cout << "last elment of vector is : - " << v.back() << endl;
    // vector<int>::iterator it;
    // it=v.insert(v.begin(),45);
    auto it = v.insert(v.begin(), 45);
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";

    v.insert(v.begin() + 3, 88);
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
    v.insert(v.begin(), 5, 0);
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
    // this can be also done by using[auto it= v.insert(v.begin(),66)];
    //auto it = v.insert(v.front(), 66);

    //inserting element from another container
    cout<<"inserting element from another container"<<"\n";
    vector<int> v2;
    v2.insert(v2.begin(), v.begin(), v.begin() + v.size());
    for (int y : v2)
    {
        cout<< y << " ";
    }
    return 0;
}