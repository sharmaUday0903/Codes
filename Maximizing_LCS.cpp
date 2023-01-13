// author : Uday Sharma
// 2022-12-30 15:17:08
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

int lcs(string s, string r)
{
    int n = s.size();
    int adj[n + 1][n + 1];

    REP(i, 0, n + 1)
    {
        REP(j, 0, n + 1)
        {
            if (i == 0 || j == 0)
            {
                adj[i][j] = 0;
            }
            else if (s[i - 1] == r[j - 1])
            {
                adj[i][j] = adj[i - 1][j - 1] + 1;
            }
            else
            {
                adj[i][j] = max(adj[i - 1][j], adj[i][j - 1]);
            }
        }
    }

    int ans = 0;
    REP(i, 1, n + 1)
    {
        ans = max(ans, adj[i][n - i]);
    }
    return ans;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    string r = s;
    reverse(r.begin(), r.end());

    cout << lcs(s, r) << endl;
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