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
        int n, k, req = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        char c = 'a', bad = 'a';
        int gap = 0;
        REP(i, 0, n)
        {
            if (k >= (s[i] - 'a'))
            {
                c = max(c, s[i]);
                req = max(req, (int)s[i] - (int)'a');
            }
            else
            {
                gap = k - req;
                bad = s[i] - gap;
                break;
            }
        }
        REP(i, 0, n)
        {
            if (s[i] <= c)
            {
                s[i] = 'a';
            }
        }
        REP(i, 0, n)
        {
            if (s[i] <= bad + gap)
            {
                s[i] = min(s[i], bad);
            }
        }
        cout<<s<<endl;
    }
}