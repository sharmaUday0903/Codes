// author : Uday Sharma
// 2022-11-12 14:21:33
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

const int MAX = 2e3 + 5;
int mem[MAX][MAX], a[MAX];

int dp(int l, int r)
{
    if (mem[l][r] != -1)
    {
        return mem[l][r];
    }
    if (l == r)
    {
        return 0;
    }
    return mem[l][r] = a[r] - a[l] + min(dp(l + 1, r), dp(l, r - 1));
}

void solve()
{
    int n;
    cin >> n;
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    memset(mem, -1, sizeof mem);
    cout << dp(0, n - 1) << endl;
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}