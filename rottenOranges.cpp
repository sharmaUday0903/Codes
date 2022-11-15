// author : Uday Sharma
// 2022-11-15 00:23:06
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
void bfs(int ii, int jj, vector<vector<int>> &vis, vector<vi> grid, vector<vector<int>> &mn, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({ii, jj});
    map<pair<int, int>, int> mapp;
    mapp[mp(ii, jj)] = 0;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        if (i > 0 && vis[i - 1][j] == 0 and grid[i - 1][j] == 1)
        {
            vis[i - 1][j] = 1;
            q.push({i - 1, j});
            mapp[{i - 1, j}] = mapp[{i, j}] + 1;
            mn[i - 1][j] = min(mn[i - 1][j], mapp[{q.front().first-1, q.front().second}] );
        }

        if (i < n - 1 && vis[i + 1][j] == 0 and grid[i + 1][j] == 1)
        {
            vis[i + 1][j] = 1;
            q.push({i + 1, j});
            mapp[{i + 1, j}] = mapp[{i, j}] + 1;

            mn[i + 1][j] = min(mn[i + 1][j], mapp[{q.front().first+1, q.front().second}] );
        }
        if (j > 0 && vis[i][j - 1] == 0 and grid[i][j - 1] == 1)
        {
            vis[i][j - 1] = 1;
            q.push({i, j - 1});
            mapp[{i , j-1}] = mapp[{i, j}] + 1;

            mn[i][j - 1] = min(mn[i][j - 1], mapp[{q.front().first, q.front().second-1}] );
        }
        if (j < m - 1 && vis[i][j + 1] == 0 and grid[i][j + 1] == 1)
        {
            vis[i][j + 1] = 1;
            q.push({i, j + 1});
            mapp[{i , j+1}] = mapp[{i, j}] + 1;

            mn[i][j + 1] = min(mn[i][j + 1], mapp[{q.front().first, q.front().second+1}] );
        }
        q.pop();
    }
}

int orangesRotting(vector<vector<int>> &grid)
{
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> mn(n + 1, vector<int>(m + 1, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == 2)
            {
                vector<vector<int>> vis(n, vector<int>(m, 0));
                bfs(i, j, vis, grid, mn, n, m);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                ans = max(ans, mn[i][j]);
            }
        }
    }

    if (ans == INT_MAX)
        return -1;
    return ans;
}

void solve()
{
    vector<vector<int>> grid;
    REP(i, 0, 10)
    {
        vi a(9);
        REP(j, 0, 9)
        {
            cin >> a[j];
        }
        grid.pb(a);
    }

    int ans = orangesRotting(grid);
    cout << ans << endl;
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}