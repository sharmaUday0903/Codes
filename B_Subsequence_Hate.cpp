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
        string s;
        cin >> s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        int p = count(s.begin(), s.end(), '1');
        int q = count(s.begin(), s.end(), '0');
        if (is_sorted(s.begin(), s.end()))
        {
            cout << 0 << endl;
        }
        else if (is_sorted(rev.begin(), rev.end()))
        {
            cout << 0 << endl;
        }
        else
        {
            int ans = min(p, q);
            int doneZero = 0;
            int doneOne = 0;
            REP(i, 0, s.length())
            {
                if (s[i] == '0')
                {
                    doneZero++;
                }
                else
                {
                    doneOne++;
                }
                int ans1 = doneZero + p - doneOne;
                int ans2 = doneOne + q - doneZero;
                ans = min(ans, min(ans1, ans2));
            }

            cout << ans << endl;
        }
    }
}
