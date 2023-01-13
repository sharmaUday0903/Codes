// author : Uday Sharma
// 2022-12-30 20:57:43
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
    set<int> s;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    if (s.size() != n)
    {
        cout << "NO\n";
        return;
    }

    bool u = true;
    REP(i, 2, n + 1)
    {
        vi c(i, 0);
        REP(j, 0, n)
        {
            c[a[j] % i]++;
        }
        int q = *min_element(c.begin(), c.end());
        if (q >= 2)
        {
            u = false;
            break;
        }
    }
    u ? cout << "YES\n" : cout << "NO\n";
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