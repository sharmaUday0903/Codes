// author : Uday Sharma
// 2022-10-30 21:45:01
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
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> g(n);
        REP(i, 0, m)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            string s;
            cin >> s;
            g[x].emplace_back(y, s[0] == 'i');
            g[y].emplace_back(x, s[0] == 'i');
        }
        vi c(n, -1);
        int ans = 0;
        REP(i, 0, n)
        {
            if (c[i] != -1)
            {
                continue;
            }
            vi que(1, i);
            c[i] = 0;
            int sum = 0;
            REP(j, 0, que.size())
            {
                sum += c[que[j]];
                for (auto p : g[que[j]])
                {
                    int to = p.first;
                    int col = c[que[j]] ^ p.second;
                    if (c[to] == -1)
                    {
                        c[to] = col;
                        que.push_back(to);
                    }
                    else
                    {
                        if (c[to] != col)
                        {
                            ans = -1;
                            break;
                        }
                    }
                }
                if (ans == -1)
                {
                    break;
                }
            }
            if (ans == -1)
            {
                break;
            }
            ans+=max(sum,que.size()-sum);
        }
        cout<<ans<<endl;
    }
}