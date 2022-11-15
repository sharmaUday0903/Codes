// author : Uday Sharma
// 2022-11-12 03:16:20
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

const int maxl = 1e7 + 5;
int sum[maxl];
int ans[maxl];
void ini()
{
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i < maxl; i++)
    {

        for (int j = 2 * i; j < maxl; j += i)
        {
            sum[j] += i;
        }
    }
    memset(ans, -1, sizeof(ans));
    REP(i, 1, maxl)
    {
        if (sum[i] + i < maxl)
            if (ans[sum[i] + i] == -1)
                ans[sum[i] + i] = i;
    }
}
void solve()
{
    int n;
    cin>>n;
    cout<<ans[n]<<endl;
}
signed main()
{
    fast;
    int t;
    t = 1;
    cin >> t;
    ini();
    while (t--)
    {
        solve();
    }
}