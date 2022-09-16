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
        int p = count(s.begin(), s.end(), '0');
        int q = count(s.begin(), s.end(), '1');
        if (p == 0 || q == 0)
        {
            cout << n << " 0\n";
        }
        else if (p == q)
        {
            cout << 1 << " " << 1 << endl;
            cout << 1 << " " << n << " " << 0 << endl;
        }
        else
        {
            string ans = s;
            vector<vi> v;
            while (!ans.empty())
            {
                string cnt = "";
                int p = count(ans.begin(), ans.end(), '0');
                int q = count(ans.begin(), ans.end(), '1');
                if (p == q)
                {
                    vi c;
                    c.pb(1);
                    c.pb(ans.size());
                    c.pb(0);
                    v.pb(c);
                    break;
                }
                vi c;
                bool u = true;
                REP(i, 0, ans.size())
                {
                    if (i != ans.size() && ((ans[i] == '0' && ans[i + 1] == '1') || (ans[i] == '1' && ans[i + 1] == '0')) && u == true)
                    {
                        c.pb(i + 1);
                        c.pb(i + 2);
                        p > q ? c.pb(1) : c.pb(0);

                        p > q ? cnt += '1' : cnt += '0';
                        u = false;
                        i++;
                    }
                    else
                    {
                        cnt += ans[i];
                    }
                }
                v.pb(c);
                ans = cnt;
            }
            cout << 1 << " " << v.size() << endl;
            for (auto c : v)
            {
                for (auto d : c)
                {
                    cout << d << " ";
                }
                cout << endl;
            }
        }
    }
}