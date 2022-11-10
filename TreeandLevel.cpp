// author : Uday Sharma
// 2022-10-31 00:04:22
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
vector<bool> vis(N, false);
vi level(N);
vi val(N);
vector<int> g[N];

void bfs(int x)
{
    level[x] = 0;
    deque<int> q;
    q.push_back(x);
    vis[x] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop_front();
        vis[p] = true;
        for (auto c : g[p])
        {
            if (!vis[c])
            {
                q.push_back(c);
                level[c] = level[p] + 1;
            }
        }
    }
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
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        bfs(0);
        int ans1=0;
        REP(i,0,n)
        {
            if (level[i]%2==0)
            {
                ans1+=val[i];
            }
            
        }
        int ans2=0;
        REP(i,0,n)
        {
            if (level[i]%2!=0)
            {
                ans2+=val[i];
            }
            
        }
        int ans=abs(ans1-ans2);
        cout<<ans<<endl;
        REP(i, 0, n)
        {
            vis[i] = false;
            g[i].clear();
            level[i] = 0;
            val[i] = 0;
        }
    }
}