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
int n, m;
bool dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &board, int idx, string &word)
{
    if (i < 0 or i >= n)
        return 0;
    if (j < 0 or j >= m)
        return 0;
    if (vis[i][j])
        return 0;
    if (board[i][j] != word[idx])
        return 0;
    if (idx == word.size() - 1)
        return 1;

    vis[i][j] = true;

    bool ans = dfs(i + 1, j, vis, board, idx + 1, word) ||
               dfs(i - 1, j, vis, board, idx + 1, word) ||
               dfs(i, j + 1, vis, board, idx + 1, word) ||
               dfs(i, j - 1, vis, board, idx + 1, word);
    vis[i][j] = false;
    return ans;
}
bool exist(vector<vector<char>> &board, string word)
{
    n = board.size();
    m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0] and dfs(i, j, vis, board, 0, word))
            {
                return true;
            }
        }
    }
}
signed main()
{
    fast;
}