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
        // int ans = 0;
        multiset<int> s;
        REP(i, 1, n)
        {
            int p = a[i - 1] - a[i];
            s.insert(p);
            // ans = max(p, ans);
        }
        if (q <= 5)
        {
            REP(i, 0, q)
            {
                int p, r;
                cin >> p >> r;
                a[p - 1] = r;
                int ans = 0;
                for (int i = 0; i < n - 1; i++)
                {
                    if ((a[i] - a[i + 1]) > ans)
                        ans = (a[i] - a[i + 1]);
                }
                cout << ans << endl;
            }
        }
        else
        {

            REP(i, 0, q)
            {
                int ii, x;
                cin >> ii >> x;
                int prev = a[ii - 1];
                a[ii - 1] = x;
                int pp = 0, qq = 0;
                if (ii != 1)
                {
                    int ppp = a[ii - 2] - prev;
                    s.erase(s.find(ppp));
                    pp = a[ii - 2] - a[ii - 1];
                    s.insert(pp);
                }
                if (ii != n)
                {
                    int qqq = prev - a[ii];
                    s.erase(s.find(qqq));

                    qq = a[ii - 1] - a[ii];
                    s.insert(qq);
                }
                auto w = *s.rbegin();
                int pwq = w;
                cout << pwq << endl;
            }
        }
    }
}