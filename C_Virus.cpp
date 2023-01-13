// author : Uday Sharma
// 2022-12-17 14:37:04
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
    int n, m;
    cin >> n >> m;
    vi b(m + 1, 0);
    REP(i, 1, m + 1)
    {
        cin >> b[i];
    }
    sortv(b);
    if (m == 1)
    {
        cout << 2 << endl;
        return;
    }
    vi a;
    a.pb(0);
    REP(i, 1, m)
    {
        a.pb(b[i + 1] - b[i] - 1);
    }
    a.pb(n - b[m] + b[1] - 1);
    sortv(a);
    int days = 0;
    int ans = m;
    REPREV(i, 1, m + 1)
    {
        int curr = a[i] - 2 * days;
        if (curr <= 0)
        {
            ans += a[i];
        }
        else
        {
            ans += 2 * days;
            days += 2;
            if (curr > 1)
            {
                ans++;
            }
            if (curr==1)
            {
                days--;
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