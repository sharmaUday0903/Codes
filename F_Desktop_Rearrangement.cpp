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
    int n, m, q;
    cin >> n >> m >> q;
    int totCnt = 0;
    vector<vector<char>> v;
    REP(i, 0, n)
    {
        vector<char> vv;
        REP(j, 0, m)
        {
            char c;
            cin >> c;
            vv.pb(c);
        }
        v.pb(vv);
    }
    vector<int> cntIcon(m, 0);
    REP(i, 0, m)
    {
        int cntt = 0;
        REP(j, 0, n)
        {
            if (v[j][i] == '*')
            {
                cntt++;
            }
        }
        totCnt += cntt;
        cntIcon[i] = cntt;
    }
    REP(i, 0, q)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (v[x][y] == '*')
        {
            v[x][y] = '.';
            cntIcon[y]--;
            totCnt--;
        }
        else
        {
            v[x][y] = '*';
            cntIcon[y]++;
            totCnt++;
        }
        int pp = totCnt / n;
        int qq = totCnt % n;
        int ans = 0;
        if (qq != 0)
        {
            REP(i, pp+1, m)
            {
                ans += cntIcon[i];
            }
            REP(i,qq,n)
            {
                if (v[i][pp]=='*')
                {
                    ans++;
                }
                
            }
        }
        else
        {

            REP(i, pp, m)
            {
                ans += cntIcon[i];
            }
        }

        cout << ans << endl;
    }
}