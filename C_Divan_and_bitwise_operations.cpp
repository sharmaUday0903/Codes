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
#define int long long int
int power(int x, int y, int mod)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y)
    {
        if (y % 2)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
const int N = 1e9 + 7;
signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, m;
        cin >> n >> m;
        int x = 0;
        REP(i, 0, m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            x |= c;
        }
        int p = power(2, n - 1, N);
        x = (x * p) % N;
        cout << x << endl;
    }
}