// author : Uday Sharma
// 2022-11-22 02:19:26
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
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    vi v;
    v.pb(a[0]);
    REP(i, 1,n)
    {
        if (v.back() != a[i])
        {
            v.pb(a[i]);
        }
    }

    int cnt = 0;
    if (v.size() == 1)
    {
        cout << "YES\n";
        return;
    }

    REP(i, 0, v.size())
    {
        if (i == 0 && v[i + 1] > v[i])
        {
            cnt++;
        }
        else if (i == v.size() - 1 && v[i - 1] > v[i])
        {
            cnt++;
        }
        else
        {
            if (v[i + 1] > v[i] && v[i - 1] > v[i])
            {
                cnt++;
            }
        }
    }
    if (cnt > 1)
    {
        cout << "NO\n";
    }
    else
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