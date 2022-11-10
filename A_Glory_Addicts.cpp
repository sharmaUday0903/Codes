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
        vi x, y;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int b[n];
        REP(i, 0, n)
        {
            cin >> b[i];
            if (a[i] == 0)
            {
                x.pb(b[i]);
                /* code */
            }
            else
            {
                y.pb(b[i]);
            }
        }
        int ans1 = 0;
        if (x.size() == 0)
        {
            REP(i, 0, y.size())
            {
                ans1 += y[i];
            }
        }
        else if (y.size() == 0)
        {
            REP(i, 0, x.size())
            {
                ans1 += x[i];
            }
        }
        else if (x.size() > y.size())
        {
            sortv(x);
            sortv(y);
            int p = y.size();
            REPREV(i, 0, x.size())
            {
                if (x.size() - i <= p)
                {
                    ans1 += 2 * x[i];
                    /* code */
                }
                else
                {
                    ans1 += x[i];
                }
            }
            REPREV(i, 0, y.size())
            {
                if (y.size() - i <= p)
                {
                    ans1 += 2 * y[i];
                    /* code */
                }
                else
                {
                    ans1 += y[i];
                }
            }
        }
        else if (x.size() == y.size())
        {
            sortv(x);
            sortv(y);
            int p = y.size();
            REPREV(i, 0, x.size())
            {
                if (x.size() - i <= p)
                {
                    ans1 += 2 * x[i];
                    /* code */
                }
                else
                {
                    ans1 += x[i];
                }
            }
            REPREV(i, 0, y.size())
            {
                if (y.size() - i <= p)
                {
                    ans1 += 2 * y[i];
                    /* code */
                }
                else
                {
                    ans1 += y[i];
                }
            }
            int pp=min(x[0],y[0]);
            ans1-=pp;
        }
        else
        {
            sortv(x);
            sortv(y);
            int p = x.size();
            REPREV(i, 0, x.size())
            {
                if (x.size() - i <= p)
                {
                    ans1 += 2 * x[i];
                    /* code */
                }
                else
                {
                    ans1 += x[i];
                }
            }
            REPREV(i, 0, y.size())
            {
                if (y.size() - i <= p)
                {
                    ans1 += 2 * y[i];
                    /* code */
                }
                else
                {
                    ans1 += y[i];
                }
            }
        }
        cout << ans1 << endl;
    }
}