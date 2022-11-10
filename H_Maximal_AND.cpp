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
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        vector<vi> dp(n, vi(33, 0));
        REP(i, 0, n)
        {
            int cnt = 0;
            int p = a[i];
            while (p)
            {
                if (p % 2 == 1)
                {
                    dp[i][cnt] = 1;
                }

                p /= 2;
                cnt++;
            }
        }
        // for(auto c:dp)
        // {
        //     for(auto d:c)
        //     {
        //         cout<<d<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        vi v;
        REPREV(i, 0, 31)
        {
            int cnt = 0;
            REP(j, 0, n)
            {
                if (dp[j][i] == 1)
                    cnt++;
            }
            int p = n - cnt;
            if (k >= p)
            {
                ans += pow(2, i);
                k -= p;
            }
        }
        cout << ans << endl;
    }
}