// author : Uday Sharma
// 2022-12-27 21:24:55
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
    vector<vi> adj(n + 1, vi(m + 1, 0));
    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        cin >> adj[i][j];
    }
    int l = 1, r = min(n, m) + 1;
    int ans = 0;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        vector<vi> psum(n + 1, vi(m + 1, 0));
        REP(i, 1, n + 1)
        {
            REP(j, 1, m + 1)
            {
                psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + (adj[i][j] >= mid);
            }
        }
        bool ok = false;
        REP(i, 1, n - mid + 2)
        {
            REP(j, 1, m - mid + 2)
            {
                int cnt, i1, j1, j2, i2;
                i1 = i;
                j1 = j;
                i2 = i + mid - 1;
                j2 = j + mid - 1;
                cnt = psum[i2][j2] - psum[i1 - 1][j2] - psum[i2][j1 - 1] + psum[i1 - 1][j1 - 1];
                if (cnt == mid * mid)
                {
                    ok = true;
                    break;
                }
            }
            if (ok)
            {
                break;
            }
        }
        if (ok)
        {
            l = mid;
        }
        else
            r = mid;
    }
    cout<<l<<endl;
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