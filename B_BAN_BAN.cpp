// author : Uday Sharma
// 2022-11-04 20:08:44
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
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else
    {
        if (n % 2 == 0)
        {
            cout << n / 2 << endl;
            int k1 = 2;
            int k2 = n * 3;
            int cntt = 0;
            while (cntt != (n / 2))
            {
                cout << k1 << " " << k2 << endl;
                k1 += 3;
                k2 -= 3;
                cntt++;
            }
        }
        else
        {
            cout << (n / 2) + 1 << endl;
            int k1 = 2;
            int k2 = n * 3;
            int cntt = 0;
            while (cntt != (n / 2)+1)
            {
                cout << k1 << " " << k2 << endl;
                k1 += 3;
                k2 -= 3;
                cntt++;
            }
        }
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