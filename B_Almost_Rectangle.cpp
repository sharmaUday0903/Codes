// author : Uday Sharma
// 2022-11-12 03:38:09
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

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    int x1, y1, x2, y2;
    bool u = true;
    REP(i, 0, n)
    {
        REP(j, 0, n)
        {
            cin >> a[i][j];
            if (a[i][j] == '*')
            {
                if (u)
                {
                    x1 = i, y1 = j;
                    u = false;
                }
                else
                {
                    x2 = i, y2 = j;
                }
            }
        }
    }
    if (x1 == x2)
    {
        if (x1 == 0)
        {
            a[n - 1][y1] = '*';
            a[n - 1][y2] = '*';
        }
        else
        {
            a[0][y1] = '*';
            a[0][y2] = '*';
        }
    }
    else if (y1 == y2)
    {
        if (y1 == 0)
        {
            a[x1][n - 1] = '*';
            a[x2][n - 1] = '*';
        }
        else
        {
            a[x1][0] = '*';
            a[x2][0] = '*';
        }
    }
    else
    {
        a[x1][y2]='*';
        a[x2][y1]='*';
    }
    for(auto c:a)
    {
        for(auto d:c)
        {
            cout<<d;
        }
        cout<<endl;
    }
    
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