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
    cin>>t;
    REP(i, 0, t)
    {
        string s;
        cin >> s;
        int n = s.length();
        vi x(n + 1);
        vi y(n + 1);
        REP(i, 0, n)
        {
            x[i + 1] = x[i] + (s[i] == 'L' ? -1 : (s[i] == 'R' ? 1 : 0));
            y[i + 1] = y[i] + (s[i] == 'D' ? -1 : (s[i] == 'U' ? 1 : 0));
        }
        int bx = 0, by = 0;
        REP(cell, 1, n + 1)
        {
            int mx = 0;
            int my = 0;
            for (char c : s)
            {
                if (c == 'U')
                    my += 1;
                if (c == 'D')
                    my -= 1;
                if (c == 'L')
                    mx -= 1;
                if (c == 'R')
                    mx += 1;
                if (mx == x[cell] && my == y[cell])
                {
                    if (c == 'U')
                        my -= 1;
                    if (c == 'D')
                        my += 1;
                    if (c == 'L')
                        mx += 1;
                    if (c == 'R')
                        mx -= 1;
                }
            }
            if (mx == 0 && my == 0)
            {
                bx = x[cell];
                by 
                = y[cell];
                break;
            }
        }
        cout << bx << " " << by << endl;
    }
}