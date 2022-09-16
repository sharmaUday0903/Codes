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
#define int long long int

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        int a[n];
        int sum = 0;
        REP(i, 0, n)
        {
            cin >> a[i];
            sum+=a[i];
        }
        vector<vector<int>> dp(n);
        REP(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            dp[u].pb(v);
            dp[v].pb(u);
        }
        vi aa;
        REP(i, 0, n)
        {
            REP(j, 0, dp[i].size() - 1)
            {
                aa.pb(a[i]);
            }
        }
        sort(aa.begin(), aa.end(), greater<int>());
        cout << sum;
        REP(i, 0, n - 2)
        {
            sum += aa[i];
            cout << " " << sum;
        }
        cout << endl;
    }
}