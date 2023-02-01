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
    int n;
    cin >> n;
    vi a(n);
    REP(i, 0, n)
    cin >> a[i];
    if (is_sorted(a.begin(), a.end()))
    {
        cout << 0 << endl;
        return;
    }
    map<int, int> m;
    REP(i, 0, n)
    {
        m[a[i]] = i + 1;
    }
    int cnt = n / 2;
    int l = -1, r = -1;
    int ans = n / 2;
    while (cnt)
    {
        int ll = m[cnt];
        int rr = m[n - cnt + 1];
        if (l == -1 && r == -1)
        {
            if (ll < rr)
            {
                ans--;
                l = ll;
                r = rr;
            }
            else
                break;
        }
        else
        {
            if (ll < l && rr > r)
            {
                ans--;
                l = ll;
                r = rr;
            }
            else
                break;
        }
        cnt--;
    }
    if (n % 2 != 0)
    {
        if (m[(n / 2) + 1] > m[n / 2] && m[(n / 2) + 1] < m[n / 2 + 2])
        {
        }
        else
            ans=n/2;
    }
    // if(ans>n/2)ans=n/2;

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