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
        vi a(n);
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int l = 0, r = 1e9;
        while (l < r)
        {
            int x = (l + r + 1) / 2;
            auto h = a;
            REPREV(i, 2, n)
            {
                if (h[i] < x)
                {
                    break;
                }
                int d = min(a[i], h[i] - x) / 3;
                h[i] -= 3 * d;
                h[i - 1] += d;
                h[i - 2] += 2 * d;
            }
            if (*min_element(h.begin(), h.end()) < x)
            {
                r = x - 1;
            }
            else
            {
                l = x;
            }
        }
        cout << l << endl;
    }
}