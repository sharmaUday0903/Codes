// author : Uday Sharma
// 2022-12-16 14:32:41
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
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    int g = __gcd(n, m);
    int l = n * m;
    l /= g;
    int p = l / n;
    string ans1="";
    REP(i, 0, p)
    {
        REP(j, 0, n)
        {
            ans1 += a[j];
        }
    }
    int q = l / m;
    string ans2="";
    REP(i, 0, q)
    {
        REP(j, 0, m)
        {
            ans2 += b[j];
        }
    }
    // cout<<ans1<<" "<<ans2<<endl;
    if (ans1 == ans2)
    {
        cout << ans1 << endl;
    }
    else
        cout << -1 << endl;
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