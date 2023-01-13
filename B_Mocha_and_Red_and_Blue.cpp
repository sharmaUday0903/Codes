// author : Uday Sharma
// 2022-12-15 19:18:09
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
#define inf 1000000000000000005
#define int long long int

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    bool u = true;
    bool o;
    int cnt = count(s.begin(), s.end(), '?');
    if (cnt == n)
    {
        REP(i, 0, n)
        {
            if (i % 2 == 0)
            {
                cout << 'B';
            }
            else
                cout << 'R';
        }
        cout << endl;
        return;
    }

    REP(i, 0, n)
    {
        if (s[i] != '?')
        {

            if (s[i] == 'R')
            {
                o = true;
            }
            else
            {
                o = false;
            }

            if (u)
            {
                int p = i;
                bool u1;
                if (s[i] == 'R')
                {
                    u1 = false;
                    /* code */
                }
                else
                {
                    u1 = true;
                }

                while (p)
                {
                    if (u1)
                    {
                        ans.pb('R');
                        u1 = false;
                    }
                    else
                    {
                        ans.pb('B');
                        u1 = true;
                    }

                    p--;
                }
                reverse(ans.begin(), ans.end());

                u = false;
            }
            ans += s[i];
        }
        else
        {
            if (!u)
            {
                if (o)
                {
                    ans += 'B';
                    o = false;
                }
                else
                {
                    ans += 'R';
                    o = true;
                }
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    fast;
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}