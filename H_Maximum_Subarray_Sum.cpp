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
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    int ans = 0;
    int mx = *max_element(a, a + n);
    if (mx < 0)
    {
        cout << mx << endl;
        /* code */
    }
    else
    {

        int aa = 0;
        int p = 0;
        REP(i, 0, n)
        {
            aa += a[i];
            aa = max(aa, p);
            ans = max(ans, aa);
        }

        cout << ans << endl;
    }
}