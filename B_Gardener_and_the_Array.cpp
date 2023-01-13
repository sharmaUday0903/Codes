// author : Uday Sharma
// 2023-01-10 17:48:41
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
    int n;
    cin >> n;
    bool u = false;
    map<int, int> m;
    vvi v(n);
    REP(i, 0, n)
    {
        int k;
        cin >> k;
        REP(j, 0, k)
        {
            int x;
            cin >> x;
            v[i].pb(x);
            m[x]++;
        }
    }
    // for(auto c:m)cout<<c.f<<" "<<c.s<<endl;
    for (auto c : v)
    {
        int cnt = 0;
        int cntt = c.size();
        for (auto d : c)
        {
            if (m[d] >= 2)
            {
                cnt++;
            }
        }
        if(cntt==cnt)u=true;
    }
    if(u)cout<<"Yes\n";
    else cout<<"No\n";
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