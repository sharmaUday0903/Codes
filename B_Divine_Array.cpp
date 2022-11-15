// author : Uday Sharma
// 2022-11-14 23:31:06
#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPREV(i, k, n) for (int i = n - 1; i >= k; i--)
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define inf 1000000000000000005
#define int long long int

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    bool u = true;
    vector<vi> g;
    g.pb(a);
    while (u)
    {
        map<int, int> m;
        REP(i, 0, n)
        {
            m[a[i]]++;
        }
        vi b;
        REP(i, 0, n)
        {
            b.pb(m[a[i]]);
        }
        if (b == a)
        {
            u = false;
        }
        else
        {
            g.pb(b);
            a = b;
        }
    }
    int q;
    cin >> q;
    REP(i, 0, q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        if (y >= g.size())
        {
            cout << g[g.size() - 1][x] << endl;
            ;
        }
        else
        {
            cout << g[y][x] << endl;
        }
    }
   
}
signed main()
{
    fast;
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}