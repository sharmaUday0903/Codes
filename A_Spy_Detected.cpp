// author : Uday Sharma
// 2022-11-12 03:47:32
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
    map<int, int> m;
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
        if (m[a[i]] == 0)
        {
            m[a[i]] = i + 1;
        }
        else
        {
            m[a[i]] = -1;
        }
    }
    int ans=0;
    for(auto c:m)
    {
        ans=max(ans,c.s);
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