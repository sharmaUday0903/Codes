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
        int ans;
        int dp[60];
        REP(i, 0, 60)
        {
            vi v;
            int a = n;
            while (a)
            {
                v.pb(a % 10);
                a /= 10;
            }
            ans = v.size() + 1;
            reverse(v.begin(), v.end());
            int val = pow(2, i);
            vi v2;
            while (val)
            {
                v2.pb(val % 10);
                val /= 10;
            }
            reverse(v2.begin(), v2.end());

            int cnt = 0;
            int j = 0;
            REP(k, 0, v.size())
            {
                if (v[k] == v2[j] && j != v2.size())
                {
                    j++;
                }
                else
                {
                    cnt++;
                }
            }
            cnt += v2.size() - j;
            dp[i] = cnt;
        }

        for (auto c : dp)
        {
            ans = min(ans, c);
        }
        cout << ans << endl;
    }
}