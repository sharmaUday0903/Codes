// author : Uday Sharma
// 2022-11-02 01:18:53
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

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, k;
        cin >> n >> k;
        deque<int> q;
        vector<int> check(n + 1, -1);
        REP(i, 0, k)
        {
            int xx;
            cin >> xx;
            xx--;
            check[xx] = 0;
            q.push_back(xx);
        }
        check[0] = 1;
        q.push_back(0);
        vector<vi> adj(n + 1);
        REP(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        while (!q.empty())
        {
            int p = q.front();
            q.pop_front();
            for (auto c : adj[p])
            {

                if (check[c] == -1)
                {
                    check[c] = check[p];
                    q.push_back(c);
                }
            }
        }

        bool ans = false;
        REP(i, 1, n)
        {
            if (check[i] == 1 && adj[i].size() == 1)
            {
                ans = true;
                break;
            }
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }
}