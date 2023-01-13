// author : Uday Sharma
// 2022-12-18 13:02:31
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
    vi b;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
        b.pb((a[i] + 1) / 2);
    }
    sortv(b);
    int ans1 = b[0] + b[1];
    // cout<<ans1<<endl;
    int ans2=inf;
    REP(i, 0, n - 2)
    {
        int p = a[i];
        int q = a[i + 2];
        int r = (p + q + 1) / 2;
        ans2 = min(ans2, r);
    }
    
    int ans3 = min(ans1,ans2);
    REP(i, 0, n - 1)
    {
        int p = max(a[i], a[i + 1]);
        int q = min(a[i], a[i + 1]);
        if ((2 * q) <= p)
        {
            ans3 = min(ans3, ((p + 1) / 2));
        }
        else
        {
            int diff=p-q;
            p=p-(2*diff);
            q=q-diff;
            ans3=min(ans3,((p+q+2)/3)+diff);
            // cout<<ans3<<endl;
        }
    }
    // cout<<ans2<<" "<<ans3<<endl;
    cout<<ans3<<endl;
        
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