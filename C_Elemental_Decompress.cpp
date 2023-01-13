// author : Uday Sharma
// 2023-01-05 20:07:01
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
    bool u = true;
    vi a(n);
    map<int, int> m;
    REP(i, 0, n)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    vi b = a;
    sortv(b);
    REP(i, 0, n)
    {
        if (b[i] <= i)
        {
            u = false;
            /* code */
        }
        if (m[a[i]] > 2)
        {
            u = false;
        }
    }
    // for (auto c : m)
    // {

    //     if (c.s >= 2 && c.f != n)
    //         u = false;
    //     if (c.s > 2)
    //     {
    //         u = false;
    //         /* code */
    //     }
    // }
    if (!u)
    {
        cout << "NO\n";
        return;
    }
    vi ans1(n, -1), ans2(n, -1);
    cout << "YES\n";
    set<int> s;
    REP(i, 1, n + 1)
    s.insert(i);
    REP(i, 0, n)
    {
        if (s.find(a[i]) != s.end())
        {
            s.erase(a[i]);
            ans1[i] = a[i];
            ans2[i] = a[i];
        }
    }
    vi cc;
    REP(i, 0, n)
    {
        if (ans1[i] == -1)
        {
            cc.pb(a[i]);
        }
    }
    sortv(cc);
    vi f(n + 1, -1);
    REP(i, 0, cc.size())
    {
        auto c = *s.begin();
        f[cc[i]] = c;
        s.erase(c);
    }

    REP(i, 0, n)
    {
        if (ans1[i] == -1)
        {

            ans1[i] = f[a[i]];
            ans2[i] = f[a[i]];
        }
    }
    for (auto c : ans1)
    {
        cout << c << " ";
    }
    cout << endl;
    map<int, int> ma;
    REP(i, 0, n)
    {
        if (ma[a[i]] > 0)
        {
            swap(ans2[i], ans2[ma[a[i]] - 1]);
        }
        else
        {

            ma[a[i]] = i + 1;
        }
    }
    for (auto c : ans2)
    {
        cout << c << " ";
    }
    cout << endl;
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