// author : Uday Sharma
// 2022-11-06 21:38:14
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
const int N = 998244353;
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

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    bool u = true;
    REP(i, 0, n - 1)
    {
        if (a[i] % a[i + 1] != 0)
        {
            u = false;
            break;
        }
    }

    int p = count(a, a + n, 1);
    if (!u)
    {
        cout << 0 << endl;
    }
    else if (p == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        int ans = 1;
        int prev = a[0];
        bool u = true;
        REP(i, 1, n)
        {
            if (a[i] == a[i - 1] && a[i] != a[0])
            {
                if (u)
                {

                    prev = a[i - 2];
                    u = false;
                }

                int f = m / a[i];
                int g = m / prev;
                int r = f - g;
                ans = (ans * r) % N;
            }
            else
            {
                int f = m / a[i];
                int g = m / prev;
                int r = f - g;
                ans = (ans * r) % N;
                u=true;
                prev=a[i];
                
            }
        }
        cout << ans << endl;
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