// author : Uday Sharma
// 2022-12-01 16:25:03
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
    vector<vi> b(n, vi(n));
    REP(i, 0, n)
    {
        REP(j, 0, n)
        {
            char x;
            cin >> x;
            b[i][j] = x - '0';
        }
    }
    REP(i, 0, n)
    {
        vi a{i};
        REP(j, 0, n)
        {
            if (b[j][i])
            {
                a.pb(j);
            }
        }
        cout<<a.size();
        for(auto x:a)
        {
            cout<<" "<<x+1;
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