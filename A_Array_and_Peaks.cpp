// author : Uday Sharma
// 2022-12-27 01:30:04
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
    int n, k;
    cin >> n >> k;
    if ((n - 1) < (2 * k))
    {
        cout << -1 << endl;
    }
    else
    {
        vi a;
        REPREV(i, 1, n + 1)
        {
            a.pb(i);
        }
        REP(i, 1, n-1)
        {
            if (k&&i%2==1)
            {
                swap(a[i-1],a[i]);
                k--;
            }
        }
        for (auto c : a)
            cout << c << " ";
        cout << endl;
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