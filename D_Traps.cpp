// author : Uday Sharma
// 2022-11-05 13:44:31
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    int ans =0;
    REP(i, 0, n)
    {
        cin >> a[i];
        ans+=a[i];
        a[i]+=i+1;
    }
    sortv(a);
    reverse(a.begin(),a.end());
    REP(i,0,k)
    {
        ans-=a[i];
    }
    REP(i,0,k)ans+=(n-i);
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