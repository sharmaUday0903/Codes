// author : Uday Sharma
// 2022-11-10 23:47:16
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
    vi a(n + 1), b(n + 1);
    REP(i, 1, n + 1)
    cin >> a[i];
    REP(i, 1, n + 1)
    b[i] = a[i] - a[i - 1];

    vector<vi> table(n + 1, vi(21));
    REP(i, 1, n + 1)
    {
        table[i][0] = b[i];
    }
    REP(j, 1, 21)
    {
        for (int i = 1; i + (1 << j) <= n + 1; i++)
        {
            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
    int l = 1, r = n, ans = 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        bool is = false;
        REP(i, 1, n - mid + 2)
        {
            int l = i + 1, r = i + mid - 1;
            int val = b[l];
            REPREV(j, 0, 21)
            {
                if ((1 << j) <= r - l + 1)
                {
                    val = __gcd(val, table[l][j]);
                    l += (1 << j);
                }
            }
            if (abs(val) > 1 || val == 0)
            {
                is = true;
                break;
            }
        }
        if (is)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
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