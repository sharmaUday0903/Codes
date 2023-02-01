// author : Uday Sharma
// 2023-02-01 16:05:18
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
#define vvi vector<vi>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int
const int MOD = 1e9 + 7;
int power(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y % 2)
        {
            res = res * x;
        }
        y = y >> 1;
        x = x * x;
    }
    return res;
}
int power(int x, int y, int mod)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y)
    {
        if (y % 2)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
int inversemod(int n, int mod)
{
    return power(n, mod - 2) % MOD;
}

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    vi a(n);
    REP(i, 0, n)
    cin >> a[i];
    sortrev(a);
    int sum = 0;
    REP(i, 0, min(n, d))
    {
        sum += a[i];
    }
    if (sum >= c)
    {
        cout << "Infinity\n";
        return;
    }
    int s=a[0]*d;
    if(s<c)
    {
        cout << "Impossible\n";
        return;
    }
    int l = 1, r = d;
    int ans=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        int p = mid+1;
        vi v(d,0);
        int tsum=0;
        REP(i,0,d)
        {
            if(i%p<=n-1)
            {
                v[i]=a[i%p];
                tsum+=v[i];
            }
        }
        // cout<<mid<<endl;
        // for(auto c:v)cout<<c<<" ";
        // cout<<endl;
        if(tsum>=c)
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
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