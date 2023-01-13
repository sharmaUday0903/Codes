// author : Uday Sharma
// 2022-12-18 17:57:26
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
    int n, m;
    cin >> n >> m;
    int nn = n;
    int cnt2 = 0, cnt5 = 0;
    int k = 1;
    while (n > 0 && n % 2 == 0)
    {
        n /= 2;
        cnt2++;
    }
    while (n > 0 && n % 5 == 0)
    {
        n /= 5;
        cnt5++;
    }
    while (cnt2 < cnt5 && k * 2 <= m)
    {
        cnt2++;
        k *= 2;
    }
    while (cnt2 > cnt5 && k * 5 <= m)
    {
        cnt5++;
        k *= 5;
    }
    while (k * 10 <= m)
    {
        k *= 10;
    }
    if (k == 1)
    {
        cout << nn * m << endl;
    }
    else
    {
        k *= m / k;
        cout << nn * k << endl;
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