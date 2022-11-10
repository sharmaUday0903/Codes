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
        string a = s;
        string b = s;
        sortv(a);
        sortrev(b);
        if (a == s)
        {
            cout << 0 << endl;
        }
        else if (b == s)
        {
            cout << 0 << endl;
        }
        else
        {
            int p = count(s.begin(), s.end(), '0');
            int ans = 0;
            REP(i, 0, p)
            {
                if (s[i] != '0')
                {
                    ans++;
                }
            }
            int q = s.length() - p;

            int j = s.length() - 1;
            while (s[j] == '1')
            {
                q--;
                j--;
            }
            int y=q;
            REP(i, 0, y)
            {
                if (s[i] == '1')
                {
                    q--;
                }
            }
            ans = min(ans, q);
            cout << ans << endl;
        }
    }
}