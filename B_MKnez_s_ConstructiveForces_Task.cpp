// author : Uday Sharma
// 2023-01-03 20:07:52
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
int power(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y % 2)
        {
            res = res * x;
        }
        y = y >> 1;
        x = x * x;
    }
    return res;
}
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
int inversemod(int n, int mod)
{
    return power(n, mod - 2) % MOD;
}

void solve()
{
    int n;
    cin >> n;
    if (n % 2 != 0)
    {
        if (n == 3)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            REP(i, 0, n)
            {
                if (i % 2 == 0)
                {
                    cout<<(n-2)/2<<" ";
                    /* code */
                }
                else
                    cout << (-1)*((n-1)/2)<< " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "YES\n";
        REP(i, 0, n)
        {
            if (i % 2 == 0)
            {
                cout << 1 << " ";
                /* code */
            }
            else
                cout << -1 << " ";
        }
        cout << endl;
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