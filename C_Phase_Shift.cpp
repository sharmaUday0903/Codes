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
        string ans = "";
        map<char, int> m;
        char w = 'a';
        REP(i, 0, n)
        {
            if (m[s[i]] != 0)
            {
                ans += m[s[i]];
            }

            else if (s[i] == w)
            {
                if (s[i] == 'z')
                {
                    w = 'a';
                }
                else
                {
                    char e = w + 1;
                    w = e;
                }

                ans += (w);
                m[s[i]] = w;
            }
            else
            {

                ans += w;
                m[s[i]] = w;
                char e = w + 1;
                w = e;
            }
        }
        cout << ans << endl;
    }
}