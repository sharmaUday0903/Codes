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
        int n, q;
        cin >> n >> q;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        vector<vi> v(n + 1);
        int p = 0;
        REP(i, 1, n)
        {
            if (a[i] < a[p])
            {
            }
            else
            {
                p = i;
            }
            v[p].pb(i);
        }
        int zero = 0;
        REP(i, 0, q)
        {
            int x, y;
            cin >> x >> y;
            x--;
            int wins = lower_bound(v[x].begin(), v[x].end(), y + 1) - v[x].begin();
            if (x == p)
            {
                wins += max(zero, y - n + 1);
            }

            cout << wins << endl;
        }
    }
}