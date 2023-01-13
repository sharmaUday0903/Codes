// author : Uday Sharma
// 2022-12-01 16:01:59
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
    int sum=0;
    vector<vi> vec(n, vi(n));
    REP(i,0,n)
    {
        REP(j,0,n)
        {
            cin>>vec[i][j];
            sum+=vec[i][j];
        }
    }
    int ans=0;
    REP(i,0,n)
    {
        int p =sum-vec[i][n-1-i];
        ans=max(ans,p);
    }
    cout<<ans<<endl;
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}