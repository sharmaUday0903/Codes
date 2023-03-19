// author : Uday Sharma
// 2023-02-01 20:35:50
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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    set<char> s;
    REP(i, 0, n)
    s.insert(a[i]);
    vector<char> v;
    for (auto c : s)
        v.pb(c);
    int siz = s.size();
    // cout<<siz<<endl;
    int ans=0;
    for(int i=0;i<(1<<siz);i++)
    {
        int cnt = 0;
        bool u = true;
        set<char> temp;
        for (int j = 0; j < siz; j++)
        {
            if (i &(1<<j))
            {
                temp.insert(v[j]);
                cnt++;
                if (cnt > k)
                {
                    u = false;
                    break;
                }
            }
        }
        // for(auto c:temp)cout<<c<<" ";
        // cout<<endl;
        if (!u)
            continue;
            int tcnt=0;
            int sum=0;
        REP(k,0,n)
        {
            if(a[k]==b[k])
            {
                tcnt++;
                sum+=tcnt;
            }
            else if (temp.find(a[k])!=temp.end())
            {
                tcnt++;
                sum+=tcnt;
            }
            else tcnt=0;
            
        } 
        ans=max(ans,sum);   
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