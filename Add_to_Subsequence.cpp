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
        map<int, int> m;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        vi v;
        for (auto c : m)
        {
            v.pb(c.s);
        }
        sortrev(v);
        int pp = v[0];
        if (m.size() == n)
        {
            cout << 0 << endl;
            /* code */
        }
        else
        {

            int p = log2(pp);
            if (pow(2, p) != pp)
            {
                /* code */
                p++;
            }

            cout << p << endl;
        }
    }
}