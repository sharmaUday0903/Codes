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
        int n;
        cin >> n;
        vi b(n + 1), p(n + 1), dist(n + 1, -1);
        REP(i, 1, n + 1)
        {
            cin >> b[i];
        }
        REP(i, 1, n + 1)
        {
            cin >> p[i];
        }
        if (b[p[1]] != p[1])
        {
            cout << -1 << endl;
        }
        else
        {
            bool u = true;
            dist[p[1]] = 0;
            REP(i, 2, n + 1)
            {
                if (dist[b[p[i]]] == -1)
                {
                    cout << -1 << endl;
                    u = false;
                    break;
                }
                dist[p[i]] = dist[p[i - 1]] + 1;
            }
            if (u)
            {
                REP(i, 1, n + 1)
                {
                    cout << dist[i] - dist[b[i]] << " ";
                }
                cout << endl;
            }
        }
    }
}