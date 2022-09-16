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
    int tt;
    cin >> tt;
    REP(i, 0, tt)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int ans = INT_MAX;
        REP(t, 0, 2)
        {
            int c[2] = {0, 0};
            REP(i, 0, n)
            {
                if ((a[i] ^ t) != b[i])
                {
                    c[(a[i] ^ t) < b[i]]++;
                }
            }
            if (c[1] == c[0] + t)
            {
                ans = min(ans, c[0] + c[1]);
            }
        }
         if(ans==INT_MAX)ans=-1;
        cout<<ans<<'\n';
        // ans == INT64_MAX ? cout << "-1\n" : cout << ans << endl;
    }
}