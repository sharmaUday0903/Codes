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
        int ans = n - 2;
        int p = count(a, a + n, a[0]);
        if (p == n)
        {
            cout << ans << endl;
        }
        else
        {
            map<int, int> m1, m2;
            REP(i, 0, n)
            {
                if (i % 2 == 0)
                {
                    m1[a[i]]++;
                }
                else
                {
                    m2[a[i]]++;
                }
            }
            vi v1, v2;
            for (auto c : m1)
            {
                v1.pb(c.s);
            }
            for (auto c : m2){

                v2.pb(c.s);
        }
        sortrev(v1);
        sortrev(v2);
        int p = v1[0];
        int q = v2[0];
        ans -= (p - 1);
        ans -= (q - 1);
        cout << ans << endl;
    }
}

}