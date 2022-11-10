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

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int a, b;
        cin >> a >> b;
        int x = (a + 1) / 2;
        int y = (a) / 2;
        int p, q;
        bool u = false;
        REP(i, 1, sqrt(b) + 1)
        {
            if (b % i == 0)
            {
                p = i;
                q = b / i;
                if ((p > x && q > x) || (p < y && q < y))
                {
                    u = true;
                    break;
                }
            }
        }
        if (u)
        {
            cout << y << " " << x << endl;
            cout << p << " " << q << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}