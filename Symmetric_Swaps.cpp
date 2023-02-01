// author : Uday Sharma
// 2023-01-16 17:07:40
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
    vi a(n), b(n);
    REP(i, 0, n)
    cin >> a[i];
    REP(i, 0, n)
    cin >> b[i];
    REP(i, 0, n)
    if (a[i] > b[i])
        swap(a[i], b[i]);
    vpi v;
    REP(i, 0, n)
    {
        v.pb(mp(a[i], b[i]));
    }
    sortv(v);
    multiset<int> s;
    REP(i, 0, n)
    s.insert(a[i]);
    int ans =  *s.rbegin()-*s.begin();
    REP(i, 0, n)
    {
        s.erase(s.find(v[i].f));
        s.insert(v[i].s);
        ans = min(ans, *s.rbegin() - *s.begin());
    }
    cout << ans << endl;
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