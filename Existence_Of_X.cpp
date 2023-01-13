// author : Uday Sharma
// 2022-11-30 23:28:28
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
    int a, b, c;
    cin >> a >> b >> c;
    int carry = 0;
    REP(i, 0, 30)
    {
        int p = a % 2;
        int q = b % 2;
        int r = c % 2;
        a /= 2;
        b /= 2;
        c /= 2;
        if (p == q && r != p)
        {
            carry ^= 1;
        }
    }

    (!carry) ? cout << "YES\n" : cout << "NO\n";
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