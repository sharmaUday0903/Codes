// author : Uday Sharma
// 2023-01-24 20:29:12
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

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = a;
    if (ans == 0)
    {
        ans = 1;
        cout << ans << endl;
        return;
    }

    ans += min(b, c) * 2;
    
    ans += min(abs(b-c)+d, a+1);
    cout << ans << endl;
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