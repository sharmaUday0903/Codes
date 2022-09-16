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
        int n, aa, bb;
        cin >> n >> aa >> bb;
        int a[n + 1];
        a[0] = 0;
        REP(i, 1, n + 1)
        {
            cin >> a[i];
        }
        int suff[n + 1];
        suff[n] = a[n];
        REPREV(i, 0, n)
        {
            suff[i] = suff[i + 1] + a[i];
        }
        int capital = 0;
        REPREV(i, 2, n + 1)
        {
            int p = suff[i];
            p -= ((n - i + 1) * a[i - 1]);
            p *= bb;
            p += ((a[i - 1] - a[i - 2]) * aa);
            int q = suff[i];
            q -= ((n - i + 1) * a[i - 2]);
            q *= bb;
            if (p < q)
            {
                capital = i - 1;
                break;
            }
        }
        int ans = 0;
        if (capital == 0)
        {
            REP(i, 1, n + 1)
            {
                ans += (a[i] * bb);
            }
            cout << ans << endl;
        }
        else
        {
            ans += (a[capital] * aa);
            int pp =a[capital];
            // cout<<pp<<endl;
            REP(i,1,n+1)
            {
                int qq=min(pp,a[i-1]);
                ans+=((a[i]-qq)*bb);
            }
            cout<<ans<<endl;
        }
    }
}