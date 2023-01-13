// author : Uday Sharma
// 2022-12-18 19:22:13
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
    int n, q;
    cin >> n >> q;
    int cnto = 0;
    int cnte = 0;
    int sume = 0,
        sumo = 0;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            cnte++;
            sume += a[i];
        }
        else
        {
            cnto++;
            sumo += a[i];
        }
    }
    REP(i, 0, q)
    {
        int x, val;
        cin >> x >> val;
        if (x == 0)
        {
            if (val % 2 == 0)
            {
                sume += (val * cnte);
            }
            else
            {
                sumo += (val * cnte);
                sumo+=sume;
                sume = 0;
                cnte = 0;
                cnto = n;
            }
        }
        else
        {
            if (val % 2 == 0)
            {
                sumo += (val * cnto);
            }
            else
            {
                sume += (val * cnto);
                sume+=sumo;
                sumo = 0;
                cnto = 0;
                cnte = n;
            }
        }

        cout << sume + sumo << endl;
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