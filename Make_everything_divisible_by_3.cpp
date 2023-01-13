// author : Uday Sharma
// 2022-12-14 20:54:22
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
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
        if (a[i] % 3 == 0)
        {
            cnt0++;
        }
        else if (a[i] % 3 == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    int p = max(cnt1, cnt2);
    int q = min(cnt1, cnt2);

    int diff = p - q;
    if (p == 0 && q == 0)
    {
        cout << 0 << endl;
        return;
        /* code */
    }
    if (diff == 0)
    {

        cout << p << endl;
        return;
    }

    int x = diff / 4;
    int y = diff % 4;
    int ans = 0;
    if (y == 1)
    {
        ans += 6;
    }
    if (y == 2)
    {
        ans += 5;
    }
    if (y == 3)
    {
        ans += 4;
    }
    int r = x * 3;
    ans += r;
    ans+=q;
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