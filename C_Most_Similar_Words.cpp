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
        int n, m;
        cin >> n >> m;
        vector<string> v;
        REP(i, 0, n)
        {
            string s;
            cin >> s;
            v.pb(s);
        }
        int ans = INT64_MAX;
        REP(i, 0, n - 1)
        {
            REP(j, i + 1, n)
            {
                int anss = 0;
                string a = v[i];
                string b = v[j];
                REP(k, 0, m)
                {
                    int p = a[k] - 'a';
                    int q = b[k] - 'a';
                    anss += abs(p - q);
                }
                ans = min(ans, anss);
            }
        }
        cout << ans << endl;
    }
}