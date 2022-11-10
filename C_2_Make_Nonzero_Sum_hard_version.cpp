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
        int a[n+1];
        REP(i, 1, n+1)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                cnt++;
            }
        }
        if ((n - cnt) % 2 != 0)
        {
            cout << -1 << endl;
        }
        else if (cnt == n)
        {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
        }
        else
        {
            int j;
            vpi ans;
            REP(i, 1, n+1)
            {
                if (a[i] == 0)
                {
                    j = i + 1;
                    while (j <= n && a[j] == 0)
                    {
                        j++;
                    }
                    ans.pb(mp(i, j - 1));
                    i = j - 1;
                    continue;
                }
                int l, r;
                l = i;
                j = i + 1;
                while (j <= n && a[j] == 0)
                {
                    j++;
                }
                r = j;
                int zeros = r - l - 1;
                if (a[l] == a[r] && zeros % 2 == 0)
                {
                    ans.pb({l, r});
                }
                else if (a[l] == a[r] && zeros % 2 == 1)
                {
                    ans.pb({l, r - 2});
                    ans.pb({r - 1, r});
                }
                else if (a[l] != a[r] && zeros % 2 == 0)
                {
                    ans.pb({l, r - 1});
                    ans.pb({r, r});
                }
                else if (a[l] != a[r] && zeros % 2 == 1)
                {
                    ans.pb({l, r});
                }
                i = j;
            }
            cout << ans.size() << endl;
            for (auto c : ans)
            {
                cout << c.f << " " << c.s << endl;
            }
        }
    }
}