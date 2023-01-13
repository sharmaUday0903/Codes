// author : Uday Sharma
// 2022-12-19 17:39:46
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
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    int mn = 0, mx = inf;
    REP(i, 0, n - 1)
    {
        if (a[i] < a[i + 1])
        {
            mx = min(mx, (a[i] + a[i + 1]) / 2);
        }
        if (a[i] > a[i + 1])
        {
            mn = max(mn, (a[i] + a[i + 1] + 1) / 2);
        }
    }
    if (mn<=mx)
    {
        cout<<mn<<endl;
    }
    else cout<<-1<<endl;
    
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