// author : Uday Sharma
// 2022-11-15 18:29:50
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

vector<int> bits(int n)
{
    vi ans;
    while (n > 0)
    {
        ans.pb(n % 2);
        n /= 2;
    }
    while (ans.size()!=32)
    {
        ans.pb(0);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    int p=m+1;
    vi bitp=bits(p);
    vi bitn=bits(n);
    vi ans(32,0);
    REP(i,0,bitp.size())
    {
        if (bitn[i]>bitp[i])
        {
            break;
        }
        else if (bitp[i]>bitn[i])
        {
            ans[i]=1;
        }
    }
    int finans=0;
    reverse(ans.begin(),ans.end());
    REP(i,0,ans.size())
    {
        if (ans[i])
        {
            finans+=pow(2,i);
        }
        
    }
    cout<<finans<<endl;
        
        
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