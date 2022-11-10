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

const int mod = 1e9 + 7;

signed main()
{
    fast;
    int n, p;
    cin >> n >> p;
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    map<int, int> present;
    vi v;
    REP(i, 0, n)
    {
        int temp = a[i];
        bool useless = false;
        while (temp > 0)
        {
            if (temp % 2 == 1)
            {
                temp--;
                temp /= 2;
            }
            else
            {
                if (temp % 4)
                {
                    break;
                }
                temp /= 4;
            }
            if (present[temp])
            {
                useless = true;
                break;
            }
        }
        if (!useless)
        {
            v.pb(a[i]);
            present[a[i]] = 1;
        }
    }
    vi dp(p + 5);
    dp[0] = 1;
    dp[1] = 1;
    REP(i, 2, p + 5)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    vi pref(p + 5);
    pref[0] = dp[0];
    REP(i, 1, p + 5)
    {
        pref[i] = (dp[i] + pref[i - 1]) % mod;
    }
    int ans = 0;
    for (auto x : v)
    {
        int bits = 0;
        while (x)
        {
            x /= 2;
            bits++;
        }
        int rem = p - bits;
        if (rem < 0)
        {
            continue;
        }

        ans = (ans + pref[rem]) % mod;
    }
    cout << ans << endl;
}