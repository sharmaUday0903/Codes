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
        int b[n];
        REP(i, 0, n)
        {
            cin >> b[i];
        }
        int ans = min(abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]), abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
        int ans1 = INT64_MAX, ans2 = INT64_MAX;
        int ans3 = INT64_MAX, ans4 = INT64_MAX;

        REP(i, 0, n)
        {
            ans1 = min(ans1, abs(a[0] - b[i]));
            ans2 = min(ans2, abs(a[n - 1] - b[i]));
            ans3 = min(ans3, abs(b[0] - a[i]));
            ans4 = min(ans4, abs(b[n - 1] - a[i]));
        }
        ans = min({ans, abs(a[0] - b[0]) + ans2 + ans4, abs(a[0] - b[n - 1]) + ans2 + ans3, 
        abs(a[n - 1] - b[0]) + ans1 + ans4, 
        abs(a[n - 1] - b[n - 1]) + ans1 + ans3});
        ans=min(ans,ans1+ans2+ans3+ans4);
        cout << ans << endl;
    }
}