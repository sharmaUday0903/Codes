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
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        cout << n - 1 << endl;
        if (n != 1)
        {
            /* code */

            int p = a[0] + a[n - 1];
            if (p % 2 == 0)
            {
                cout << 1 << " " << n << endl;
                a[0] = a[n - 1];
                REP(i, 1, n - 1)
                {
                    if (a[i] % 2 == a[0] % 2)
                    {
                        cout << i + 1 << " " << n << endl;
                    }
                    else
                    {
                        cout << 1 << " " << i + 1 << endl;
                    }
                }
            }
            else
            {
                cout << 1 << " " << n << endl;
                a[n - 1] = a[0];
                REP(i, 1, n - 1)
                {
                    if (a[i] % 2 == a[0] % 2)
                    {
                        cout << i + 1 << " " << n << endl;
                    }
                    else
                    {
                        cout << 1 << " " << i + 1 << endl;
                    }
                }
            }
        }
    }
}