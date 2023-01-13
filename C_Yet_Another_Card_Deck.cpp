// author : Uday Sharma
// 2022-12-27 17:44:21
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
    int n, q;
    cin >> n >> q;
    vi pos(51, n + 2);
    REP(i, 0, n)
    {
        int x;
        cin >> x;
        pos[x] = min(pos[x], i + 1);
    }

    REP(i, 0, q)
    {
        int x;
        cin >> x;
        cout << pos[x] << " ";
        REP(i, 1, 51)
        {
            if (pos[i] < pos[x])
            {
                pos[i]++;
            }
        }
        pos[x] = 1;
    }
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}