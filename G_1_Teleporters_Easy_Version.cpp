// author : Uday Sharma
// 2023-02-03 22:27:45
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
        a[i] += i + 1;
    }
    sortv(a);
    int cnt = 0;
    int sum = 0;
    REP(i, 0, n)
    {
        if (a[i] + sum <= m)
        {
            cnt++;
            sum += a[i];
        }
        else break;
    }
    cout<<cnt<<endl;
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