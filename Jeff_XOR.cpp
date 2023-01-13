// author : Uday Sharma
// 2022-12-16 12:47:53
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
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    vi a(n);
 
    REP(i, 0, n)
    {
        
        cin >> a[i];
    }
       if (n==1)
    {
        cout<<0<<endl;return;
    }
    
    vi pref(n + 1, 0);
    m[0]++;
    REP(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] ^ a[i-1];
        m[pref[i]]++;
    }
    int ans = 0;
    REP(i, 0, n + 1)
    {
        int p = pref[i]^x;
        ans+=m[p];
    }
    ans/=2;
    
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