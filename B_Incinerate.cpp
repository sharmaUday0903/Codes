// author : Uday Sharma
// 2022-12-19 20:06:40
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
    vi a(n), b(n);
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    REP(i, 0, n)
    {
        cin >> b[i];
    }
    multiset<pair<int, int>> m;
    REP(i, 0, n)
    {
        m.insert({b[i], a[i]});
    }

    vi ans;
    int val = k;
    int sum = 0;
    bool u = true;
    int p = *max_element(a.begin(), a.end());
    while (val > 0 && p > 0&&!m.empty())
    {
        p -= val;
        sum += val;
        while (!m.empty())
        {
            auto y = *m.begin();
            if (y.second <= sum)
            {
                m.erase(m.find(y));
            }
            else
            {
                break;
            }
        }
        if (!m.empty())
        {
            auto z=*m.begin();
            val-=z.first;
        }
        
    }
    

    if (p<=0)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
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