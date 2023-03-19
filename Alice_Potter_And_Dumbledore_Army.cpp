// author : Uday Sharma
// 2023-02-08 21:26:22
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
#define vvi vector<vi>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int
const int MOD = 1e9 + 7;
int power(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y % 2)
        {
            res = res * x;
        }
        y = y >> 1;
        x = x * x;
    }
    return res;
}
int power(int x, int y, int mod)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y)
    {
        if (y % 2)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
int inversemod(int n, int mod)
{
    return power(n, mod - 2) % MOD;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vpi v;
    multiset<int> s;
    REP(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        v.pb({x, y});
    }
    vi ans(m);
    // map<int, int> map;
    // ans[0] = v[0].second;
    // map[v[0].f] = v[0].s;
    // s.insert(v[0].s);
    vi cnt(n + 1, 0);
    int val = v[0].s;
    cnt[v[0].f] = v[0].s;
    ans[0]=v[0].s;
    REP(i, 1, m)
    {
        if (cnt[v[i].f]==0)
        {
            cnt[v[i].f] = v[i].s;
            // s.insert(v[i].s);
            // auto it = s.rbegin();
            // int p = *it;
            val = v[i].s;
            ans[i] = ans[i - 1] + val;
        }
        else
        {
            // s.erase(s.find(map[v[i].f]));
            cnt[v[i].f] += v[i].s;
            //  cout<<map[v[i].f]<<" "<<i<<" "<<endl;
            // s.insert(map[v[i].f]);
            // auto it = s.rbegin();
            // int p = *it;
             val = cnt[v[i].f];
            ans[i] = ans[i - 1] + val;
            // s.erase(s.find(map[v[i].f]));
        }
    }
    for (auto c : ans)
        cout
            << c << endl;
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}