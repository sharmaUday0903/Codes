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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec;
    vpi g;
    REP(i, 0, m)
    {
       int u,v;
       cin>>u>>v;
       g.pb(mp(u,v));
    }
    REP(i,0,m)
    {
        if (g[i].first<g[i].s)
        {
            vec[g[i].f].pb(g[i].s);
        }
        else
        {
            vec[g[i].s].pb(g[i].f);
            
        }
        
        
    }
    int q;
    cin >> q;
    REP(i, 0, q)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1)
        {
            if (x < y)
            {
                vec[x].pb(y);
            }
            else
            {
                vec[y].pb(x);
            }
        }
        else if (z == 2)
        {
            if (x < y)
            {
                for (auto c = vec[x].begin(); c != vec[x].end(); ++c)
                {
                    if (*c == y)
                    {
                        vec[x].erase(c);
                    }
                }
            }
            else
            {
                for (auto c = vec[y].begin(); c != vec[y].end(); ++c)
                {
                    if (*c == x)
                    {
                        vec[y].erase(c);
                    }
                }
            }
        }
        else
        {
            int count = 0;
            for (auto c : vec)
            {
                if (c.size() == 0)
                {
                    count++;
                }
            }
            cout << count << endl;
        }
    }
}