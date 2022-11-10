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
        bool u = false;
        vector<string> v;
        REP(i, 0, n)
        {
            string x;
            cin >> x;
            if (x.length() == 1)
            {
                u = true;
            }
            else if (x.length() == 2 && x[0] == x[1])
            {
                u = true;
            }
            else if (x.length() == 3 && x[0] == x[2])
            {
                u = true;
            }
            if (x.size() != 1)
            {
                v.pb(x);
            }
        }
        if (u)
        {
            cout << "YES\n";
        }
        else
        {
            set<string> s, e;
            REP(i, 0, v.size())
            {
                string x = v[i];
                reverse(x.begin(), x.end());
                if (x == v[i])
                {
                    u = true;
                }
                if (e.count(v[i]))
                {
                    u = true;
                }
                if (s.count(v[i].substr(1)))
                {
                    u = true;
                }
                s.insert(x);
                e.insert(x);
                e.insert(x.substr(1));
            }
            u ? cout << "YES\n" : cout << "NO\n";
        }
    }
}