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
        int sum = 0;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            sum += a[i];
        }
        int ans = n;
        REP(i, 1, n+1)
        {
            if (sum % i == 0)
            {
                int p = sum / i;
                vi v;
                int cnt = 0;
                int seg = 0;
                REP(j, 0, n)
                {
                    cnt += a[j];
                    seg++;
                    if (cnt == p)
                    {
                        v.pb(seg);
                        seg = 0;
                        cnt = 0;
                    }
                }
                if (cnt == 0 && v.size() == i)
                {
                    int w = *max_element(v.begin(), v.end());
                    ans = min(w, ans);
                }
            }
        }
        cout << ans << endl;
    }
}