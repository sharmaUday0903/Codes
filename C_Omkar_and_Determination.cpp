// author : Uday Sharma
// 2022-11-02 10:39:29
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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    REP(i, 0, n)
    {
        string c;
        cin >> c;
        v[i] = c;
    }
    vi invalid(m, 0);
    int q;
    cin >> q;
    REP(i, 1, n)
    {
        REP(j, 1, m)
        {
            if (v[i - 1][j] == 'X' && v[i][j - 1] == 'X')
            {
                invalid[j] = 1;
            }
        }
    }
    REP(i,1,m)
    {
        invalid[i]+=invalid[i-1];
    }
    REP(i,0,q)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if (invalid[y]-invalid[x]==0)
        {
            cout<<"YES\n";
        }
        else cout<<"NO\n";
        
    }
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