#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
 
void print(std::list<std::string> const &list)
{
    for (auto const &i : list)
    {
        std::cout << i << std::endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    list<string> l_1 = {"1 3"};
    list<string> l_2 = {"1 2", "1 3", "2 3"};
 
    if (n == 1)
        print(l_1);
    else if (n == 2)
        print(l_2);
    else
    {
        FOR(i, 3, n + 1)
        {
            list<string> l(l_2);
            l.reverse();
            list<string>::iterator li;
            for (li = l.begin(); li != l.end(); ++li)
            {
                reverse((*li).begin(), (*li).end());
            }
            ll j = 0;
            li = l.begin();
            while (j != (pow(2, i - 1) / 2 - 1))
            {
                li++;
                j++;
            }
            reverse((*li).begin(), (*li).end());
            l.push_front("1 2");
            l.push_back("2 3");
            for (li = l_1.begin(); li != l_1.end(); ++li)
            {
                l.push_back(*li);
            }
            list<string>::reverse_iterator rli;
            for (rli = l_1.rbegin(); rli != l_1.rend(); ++rli)
            {
                l.push_front(*rli);
            }
 
            l_1.clear();
            // copy(l_2.begin(), l_2.end(), l_1.begin());
            for (li = l_2.begin(); li != l_2.end(); ++li)
            {
                l_1.push_back(*li);
            }
 
            l_2.clear();
            // copy(l.begin(), l.end(), l_2.begin());
            for (li = l.begin(); li != l.end(); ++li)
            {
                l_2.push_back(*li);
            }
        }
        print(l_2);
    }
 
    return 0;
}
