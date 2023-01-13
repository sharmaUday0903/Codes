// author : Uday Sharma
// 2022-12-27 02:16:29
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
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vi a(n), b(n);
    vi diff;
    REP(i, 0, n)
    cin >> a[i];
    REP(i, 0, n)
    {
        cin >> b[i];
        diff.pb(abs(a[i] - b[i]));
    }
    multiset<int> m;
    for (auto c : diff)
        m.insert(c);
    REP(i, 0, k1 + k2)
    {
        auto c = *m.rbegin();
        m.erase(m.find(c));
        c--;
        m.insert(abs(c));
    }
    int ans=0;
    for(auto c:m)
    {
        ans+=c*c;
    }
    cout<<ans<<endl;
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