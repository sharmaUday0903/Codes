// author : Uday Sharma
// 2022-11-30 23:35:19
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
    vi a(n), b(n);
    REP(i, 0, n)
    cin >> a[i];
    REP(i, 0, n)
    cin >> b[i];
    vector<pair<long double, int>> vec;
    REP(i, 0, n)
    {
        vec.pb({(long double)b[i] / (long double)a[i], i});
    }
    sortv(vec);
    vi order;
    for(auto c:vec)
    {
        order.pb(c.s);
    }
    int ans=0;
    int x=0;
    for(auto c:order)
    {
        ans+=x*(b[c]);
        x+=a[c];
    }
    cout<<ans<<endl;
        
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