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
        int cnt = 0;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            int p = a[i];
            while (p % 2 == 0)
            {
                p /= 2;
                cnt++;
            }
        }
        bool u = true;
        int cnt1 = 0;
        vi v;
        REP(i, 1, n + 1)
        {
            int p = i;
            int q = 0;
            while (p % 2 == 0)
            {
                p /= 2;
                cnt1++;
                q++;
            }
            v.pb(q);
        }
        sortrev(v);
        if ((cnt + cnt1) < n)
        {
            cout << -1 << endl;
        }
        else
        {
            if (cnt >= n)
            {
                cout << 0 << endl;
            }
            else
            {
                int ans = 0;
                REP(i, 0, v.size())
                {
                    cnt+=v[i];
                    ans++;
                    if (cnt>=n)
                    {
                        break;
                    }
                    
                }
                cout << ans << endl;
            }
        }
    }
}