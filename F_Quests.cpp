// author : Uday Sharma
// 2022-11-21 22:27:10
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
    int n, c, d;
    cin >> n >> c >> d;
    int sum = 0;
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    int mx = *max_element(a, a + n);
    sort(a, a + n, greater<int>());
    int cnt = 0;
    REP(i, 0, min(d, n))
    {
        cnt += a[i];
    }
    if (mx * d < c)
    {
        cout << "Impossible\n";
        return;
    }
    if (cnt >= c)
    {
        cout << "Infinity\n";
        return;
    }
    int ans = 0;
    int l = 0, r = 1e16 + 5;
    int y = c % sum;
    int exidx = -1;
    int cntt = 0;
    REP(i, 0, n)
    {
        cntt += a[i];
        if (cntt >= y)
        {
            exidx = i+1;
            break;
        }
    }
    d-=exidx;
    c-=y;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        

    }
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