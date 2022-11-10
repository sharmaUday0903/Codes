// author : Uday Sharma
// 2022-11-05 14:00:53
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
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    multiset<int> x, y;
    for (auto &p : m)
    {
        y.insert(p.s);
    }
    int sum = 0;
    int ans = 1e9;
    int holes = 0;
    REP(mex, 0, n + 1)
    {
        while (!y.empty() && sum + (*y.begin()) <= k)
        {
            sum += (*y.begin());
            x.insert(*y.begin());
            y.erase(y.begin());
        }
        if (holes <= k)
        {
            ans = min(ans, (int)y.size());
        }
        auto it = m.find(mex);
        if (it == m.end())
        {
            holes += 1;
        }
        else
        {
            if (x.find(it->second) != x.end())
            {
                sum -= it->s;
                x.erase(x.find(it->s));
            }
            else
            {
                y.erase(y.find(it->s));
            }
        }
    }
    cout<<ans<<endl;
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