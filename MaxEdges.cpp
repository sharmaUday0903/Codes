// author : Uday Sharma
// 2022-11-13 10:36:58
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
    int n, l, k;
    cin >> n >> k >> l;
    if (k + l > n)
    {
        int ex = k + l - n;
        n -= ex;
        k -= ex;
        l -= ex;
        int ans = l * k;
        cout << ans << endl;
    }
    else
    {
        int ans1 = 0;
        int ex = n - k - l;
        ans1 = k * l;
        ans1 += (ex * k);
        ans1 += (ex * l);
        int pp = (ex * (ex - 1))/2;
        ans1 += pp;
        int ans2 = 0;
        int e = min(l, k);
        n -= e;
        k -= e;
        l -= e;
        int exx = n - k - l;
        ans2 += k * l;
        ans2 += (exx * k);
        ans2 += (exx * l);
        int qq=(exx*(exx-1))/2;
        ans2+=qq;
        int ans=max(ans1,ans2);
        cout<<ans<<endl;
    }
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