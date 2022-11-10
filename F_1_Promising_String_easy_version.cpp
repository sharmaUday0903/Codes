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
        string s;
        cin >> s;
        vi pref(n + 1, 0);
        REP(i, 1, n + 1)
        {
            pref[i] = pref[i - 1] + (s[i - 1] == '+' ? 1 : -1);
        }
        // for(auto c:pref)
        // {
        //     cout<<c<<" ";
        // }
        // cout<<endl;
        vi minus(n + 1, 0);
        REP(i, 2, n)
        {
            if (s[i - 1] == '-' && s[i - 2] == '-')
            {
                minus[i] = minus[i - 1] + 1;
            }
        }

        int ans = 0;
        REP(i, 0, n - 1)
        {
            REP(j, i + 1, n)
            {
                int p = i + 1;
                int q = j + 1;
                int y = pref[q] - pref[p -1];
                if (y == 0)
                {
                    ans++;
                    // cout<<p<<" "<<q<<endl;
                    continue;
                }
                if (y > 0)
                {
                    continue;
                }
                else
                {
                    if (abs(y) % 3 == 0)
                    {
                        ans++;
                        /* code */
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}