// author : Uday Sharma
// 2022-11-12 03:30:10
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
    int n, c;
    cin >> n >> c;
    int ans = inf;
    vi a(n), b(n);
    REP(i, 0, n)
    cin >> a[i];
    REP(i, 0, n - 1)
    cin >> b[i];
    b[n - 1] = inf;
    vi day(n + 1), money(n + 1);
    day[0] = 0;
    money[0] = 0;
    int zero = 0;
    REP(i, 0, n)
    {
        int i_need = max(zero, (c - money[i] + a[i] - 1) / a[i]);
        ans = min(ans, day[i] + i_need);

        i_need = max(0ll, (b[i] - money[i] + a[i] - 1) / a[i]);
        day[i + 1] = day[i] + i_need + 1;

        money[i + 1] = money[i] + i_need * a[i] - b[i];
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