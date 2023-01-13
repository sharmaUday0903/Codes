// author : Uday Sharma
// 2022-12-15 03:33:03
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
    vector<vector<char>> v;
    REP(i, 0, n)
    {
        vector<char> a;
        REP(j, 0, m)
        {
            char x;
            cin >> x;
            a.pb(x);
        }
        v.pb(a);
    }
    vector<vector<char>> ans(n, vector<char>(m, '.'));
    REP(j, 0, m)
    {
        stack<char> s;
        REP(i, 0, n)
        {
            if (v[i][j] == '*')
            {
                s.push('*');
            }

            if (v[i][j] == 'o')
            {
                ans[i][j] = 'o';
                int p = i - 1;
                while (!s.empty())
                {
                    ans[p][j] = '*';
                    s.pop();
                    p--;
                }
            }
        }
        if (!s.empty())
        {
            int p =n-1;
            while (!s.empty())
            {
                ans[p][j]='*';
                p--;
                s.pop();
            }
            
        }
    }
    for(auto c:ans)
    {
        for(auto d:c)
        {
            cout<<d;
        }
        cout<<endl;
    }
    cout<<endl;
        
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