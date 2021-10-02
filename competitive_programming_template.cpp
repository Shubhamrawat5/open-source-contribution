#include <bits/stdc++.h>

using namespace std;

#define tc ll t sc cin >> t sc while (t--)
#define sc ;
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define set_bits __builtin_popcountll
#define sz(v) ((int)((v).size()))
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) ((v).begin()), ((v).end())
#define allr(w) ((w).rbegin()), ((w).rend())

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

/*********************************/

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

bool isPowOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}

bool cmp1(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first < b.first);
}

bool cmp2(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

ll min3(ll a, ll b, ll c)
{
    return min(a, min(b, c));
}

ll min4(ll a, ll b, ll c, ll d)
{
    return min(a, min(b, min(b, c)));
}

ll max3(ll a, ll b, ll c)
{
    return max(a, max(b, c));
}

ll max4(ll a, ll b, ll c, ll d)
{
    return max(a, max(b, max(b, c)));
}

/*********************************/

void solve()
{
}

const int INF = 1000000000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    tc
    {
        solve();
    }
    return 0;
}