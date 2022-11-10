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
    int n;
    cin >> n;
    int ans = 0;
    vi ret;
    while (n > 0)
    {
        int b = 0;
        while ((1 << (b + 1)) <= n)
        {
            b++;
        }
        if (__builtin_popcount(n) == 1)
        {
            if (b > 0)
            {
                ret.pb(b);
                ans++;
            }
            break;
        }
        ret.pb(b + 1);
        n ^= (1 << (b + 1)) - 1;
        n += 1;
        ans += 2;
    }
    cout << ans << endl;
    for (auto c : ret)
    {
        cout << c << " ";
    }
}