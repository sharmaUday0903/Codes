// author : Uday Sharma
// 2022-11-19 15:14:12
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
    REP(i, 1, n + 1)
    {
        s.insert(i);
    }
    bool u = true;
    int a[n / 2];
    REP(i, 0, n / 2)
    {
        cin >> a[i];
        if (s.count(a[i]))
        {
            
            s.erase(a[i]);
        }
        else
            u = false;
    }
    vi ans(n);
    REPREV(i, 0, n / 2)
    {
        ans[(2 * i) + 1] = a[i];
        auto c = s.upper_bound(a[i]);
        if (c == s.begin())
        {
            u = false;
            break;
        }
        else
        {
            ans[2 * i] = *prev(c);
            s.erase(ans[2 * i]);
        }
    }
    if (u)
    {
        for (auto c : ans)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
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