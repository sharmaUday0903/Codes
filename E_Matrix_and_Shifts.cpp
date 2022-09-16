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
    REP(ii, 0, t)
    {
        int n;
        cin >> n;
        int cnt1 = 0;
        char a[n][n];
        REP(i, 0, n)
        {
            REP(j, 0, n)
            {
                cin >> a[i][j];
                if (a[i][j] == '1')
                {
                    cnt1++;
                }
            }
        }
        map<int, int> m1;
        REP(i, 0, n)
        {
            REP(j, 0, n)
            {
                if (a[i][j] == '1')
                {
                    int p = j - i;
                    if (p < 0)
                    {
                        p += n;
                    }
                    m1[p]++;
                }
            }
        }
        int p = 0;
        if (!m1.empty())
        {
            /* code */
            vi v;
            for (auto c : m1)
            {
                v.pb(c.s);
            }
            p = max(p, *max_element(v.begin(), v.end()));
        }

        if (p >= n)
        {
            cnt1 -= n;
            cout << cnt1 << endl;
        }
        else
        {
            cnt1 -=  p;
            cnt1+=(n-p);
            cout << cnt1 << endl;
        }
    }
}