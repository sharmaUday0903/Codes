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
        bool u = true;
        int ans = 0;
        int p = 0;
        int cnt2 = 0;
        int aa = n;
        while (aa != 1)
        {
            aa /= 2;
            cnt2++;
            /* code */
        }
        while (p != cnt2)
        {
            int q = pow(2, p);
            for (int i = 0; i < n - q; i += (q*2))
            {
                int val = abs(a[i] - a[i + q]);
                if (val != q)
                {
                    u = false;
                    break;
                }
                else
                {
                    if (a[i] > a[i + q])
                    {
                        ans++;
                        swap(a[i], a[i + q]);
                    }
                }
            }
            p++;
            if (!u)
            {
                break;
                /* code */
            }
        }
        if (!u)
        {
            cout << -1 << endl;
            /* code */
        }
        else
        {
            cout << ans << endl;
        }
    }
}
