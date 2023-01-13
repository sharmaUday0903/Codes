// author : Uday Sharma
// 2022-12-30 15:33:19
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
    string s;
    cin >> s;

    int seg = 1, ans = n, l = 0, r = k - 1;
    REP(i, 1, k)
    {
        if (s[i] != s[i - 1])
        {
            seg++;
        }
    }
    if (s[r] == '0')
        ans = min(ans, seg);
    else
        ans = min(ans, seg-1);
    while (r + 1 < n)
    {
        l++;
        if (s[l] != s[l - 1])
        {
            seg--;
        }
        r++;
        if (s[r] != s[r - 1])
        {
            seg++;
        }
        if (s[r]=='0')
        {
            ans=min(ans,seg);
        }
        else
        {
            ans=min(ans,seg-1);
        }
        
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