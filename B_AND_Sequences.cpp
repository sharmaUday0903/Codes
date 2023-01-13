// author : Uday Sharma
// 2022-12-27 01:43:22
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

const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    REP(i, 0, n)
    cin >> a[i];
    int ad = a[0];
    REP(i, 1, n)
    ad &= a[i];
    int cnt = count(a.begin(), a.end(), ad);
    if (cnt == 0)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    REP(i, 1, n - 1)
    {
        ans *= i;
        ans %= mod;
    }
    REP(i, cnt - 2 + 1, cnt + 1)
    {
        ans *= i;
        ans %= mod;
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