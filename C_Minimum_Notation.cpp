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
        int n = s.length();
        string ans = "";
        int p = 0;
        vector<bool> v(n, false);
        REP(j, 0, 10)
        {
            char cc=j+48;
            REP(i, p, n)
            {
                if (s[i] == cc)
                {
                    ans += s[i];
                    p=i+1;
                    v[i] = true;
                }
            }
        }
        string w = "";
        REP(i, 0, n)
        {
            if (v[i] == false)
            {
                w += s[i];
            }
        }
        sortv(w);
        REP(i, 0, w.size())
        {

            int p = w[i] - 48;
            p++;
            int ppp = 9;
            p = min(p, ppp);
            char cc = p + 48;
            ans += cc;
        }
        sortv(ans);
        cout << ans << endl;
    }
}