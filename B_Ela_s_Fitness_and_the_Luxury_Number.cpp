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
        int l, r;
        cin >> l >> r;
        int orL=l;
        int p = sqrt(l);
        int q = sqrt(r);
        int ans = (q - p - 1) * 3;
        int zer = 0;
        ans = max(ans, zer);
        int left = l % p;
        if (left != 0)
        {
            l += p - left;
        }

        int e = min((p + 1) * (p + 1), r);
        if (l % p == 0 && l <= e && l < (p + 1) * (p + 1))
        {
            ans++;
        }
        l += p;
        if (l % p == 0 && l <= e && l < (p + 1) * (p + 1))
        {
            ans++;
        }
        l += p;
        if (l % p == 0 && l <= e && l < (p + 1) * (p + 1))
        {
            ans++;
        }

        if (p != q)
        {

            int right = r % q;
            r -= right;
            int f = max(orL, q * q);
         
            if (r % q == 0 && r >= f)
            {
                ans++;
            }
            r -= q;
            if (r % q == 0 && r >= f)
            {
                ans++;
            }
            r -= q;
            if (r % q == 0 && r >= f)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}