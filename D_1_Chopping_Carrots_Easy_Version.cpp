// author : Uday Sharma
// 2022-10-28 17:12:07
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
        int n, k;
        cin >> n >> k;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int ans = inf;
        REP(v, 1, a[0] + 1)
        {
            int cm = v;
            REP(i, 0, n)
            {
                int p = min(k, (v ? (a[i] / v) : k));
                cm=max(cm,a[i]/p);
            }
            ans=min(ans,cm-v);
        }
        cout<<ans<<endl;
    }
}