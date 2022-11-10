// author : Uday Sharma
// 2022-10-30 23:50:55
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

const int N = 1e5 + 5;
vi val(N);
vector<bool> vis(N, false);
vector<int> Xor_arr(N, 0);
vector<int> g[N];

int dfs(int u)
{
    Xor_arr[u] = val[u];
    vis[u] = true;
    for (auto c : g[u])
    {
        if (!vis[c])
        {
            Xor_arr[u] ^= dfs(c);
        }
    }

    return Xor_arr[u];
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        REP(i, 0, n)
        {
            cin >> val[i];
        }
        REP(i, 0, n - 1)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].pb(y);
            g[y].pb(x);
        }
        dfs(0);
        int ans = *max_element(Xor_arr.begin(), Xor_arr.end());
        cout << ans << endl;
        REP(i, 0, n+1)
        {
            vis[i] = false;
            g[i].clear();
            Xor_arr[i]=0;
        }
        
    }
}