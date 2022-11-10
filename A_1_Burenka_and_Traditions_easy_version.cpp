// author : Uday Sharma
// 2022-10-31 22:26:39
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

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        vi a(n);
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        vi b(n + 1);
        REP(i, 0, n)
        {
            b[i + 1] = b[i] ^ a[i];
        }
        map<int, int> last;
        vi dp(n + 1);
        last[0] = 0;
        dp[0] = 0;
        REP(i, 1, n + 1)
        {
            dp[i] = dp[i - 1];
            if (last.find(b[i]) != last.end())
            {
                dp[i] = max(dp[i], dp[last[b[i]]] + 1);
            }
            last[b[i]]=i;
        }
        cout<<n-dp[n]<<endl;
    }
}