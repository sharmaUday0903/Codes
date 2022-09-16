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
        int p = abs(s[0] - 48 - s[n - 1] + 48);
        cout << p << " ";
        vi v;
        v.pb(1);
        int pp = s[0] - 96;
        int qq = s[n - 1] - 96;
        if (pp >= qq)
        {
            while (pp != qq-1)
            {
                REP(i, 1, n - 1)
                {
                    int d = s[i] - 96;
                    if (d == pp)
                    {
                        v.pb(i + 1);
                    }
                }
                pp--;
            }
        }
        else
        {
            while (pp != qq+1)
            {
                REP(i, 1, n - 1)
                {
                    int d = s[i] - 96;
                    if (d == pp)
                    {
                        v.pb(i + 1);
                    }
                }
                pp++;
            }
        }
        v.pb(n);
        cout << v.size() << endl;
        for (auto c : v)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}