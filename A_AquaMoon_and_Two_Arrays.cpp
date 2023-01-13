// author : Uday Sharma
// 2022-12-15 18:07:34
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
    vi a(n), b(n);
    int sum1 = 0, sum2 = 0;
    REP(i, 0, n)
    {
        cin >> a[i];
        sum1 += a[i];
    }
    REP(i, 0, n)
    {
        cin >> b[i];
        sum2 += b[i];
    }
    if (sum1 == sum2)
    {
        vi ans1, ans2;
        REP(i, 0, n)
        {
            if (a[i] > b[i])
            {
                int p = a[i] - b[i];
                while (p)
                {
                    ans1.pb(i + 1);
                    p--;
                }
            }
            else if (a[i] < b[i])
            {
                int p = b[i] - a[i];
                while (p)
                {
                    ans2.pb(i + 1);
                    p--;
                }
            }
        }
        cout<<ans1.size()<<endl;
        REP(i,0,ans1.size())
        {
            cout<<ans1[i]<<" "<<ans2[i]<<endl;
        }
    }
    else
    {
        cout << -1 << endl;
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