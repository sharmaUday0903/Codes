// author : Uday Sharma
// 2023-01-13 23:56:14
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
    int m;
    cin >> m;
    map<int, int> r;
    REP(i, 0, m)
    {
        int x;
        cin >> x;
        r[x]++;
    }
    REP(i, 0, n)
    {
        if (a[i] < b[i])
            {cout << "NO\n";
        return;}
    }
    stack<int> s;
    REP(i, 0, n)
    {
        int p = a[i], q = b[i];
        while (s.size() && s.top() < q)
        {
            s.pop();
        }
        if (a[i] == b[i])
            continue;
        if (s.size() && s.top() == q)
            continue;
        if (r[q] == 0)
        {
            cout << "NO\n";
            return;
        }
        r[q]--;
        s.push(q);
    }
    cout << "YES\n";
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