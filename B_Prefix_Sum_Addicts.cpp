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
        int n, k;
        cin >> n >> k;
        int a[k];
        REP(i, 0, k)
        {
            cin >> a[i];
        }
        if (k == 1)
        {
            cout << "YES\n";
            /* code */
        }
        else
        {
            bool u = true;
            int cnt = a[k - 1] - a[k - 2];
            REPREV(i, 1, k - 1)
            {
                int p = a[i] - a[i - 1];
                if (cnt < p)
                {
                    u = false;
                    break;
                    /* code */
                }
                else
                {
                    cnt = p;
                }
            }

            int q = n - k + 1;
            if (a[0] > cnt * q)
            {
                u = false;
                /* code */
            }

            u ? cout << "Yes\n" : cout << "No\n";
        }
    }
}