// author : Uday Sharma
// 2022-10-28 15:08:16
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

auto check(string s)
{
    int bal = 0;
    for (auto c : s)
    {
        if (c == '(')
            bal++;
        if (c == ')')
            bal--;
        if (bal < 0)
            return false;
    }
    return bal == 0;
}

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
        int op = n / 2, cl = n / 2;
        vi pos;
        REP(i, 0, n)
        {
            if (s[i] == '?')
            {
                pos.pb(i);
            }
            else if (s[i] == '(')
            {
                op--;
            }
            else
                cl--;
        }
        REP(i, 0, pos.size())
        {
            if (i < op)
            {
                s[pos[i]] = '(';
            }
            else
                s[pos[i]] = ')';
        }
        bool ok = true;
        if (op > 0 && cl > 0)
        {
            swap(s[pos[op - 1]], s[pos[op]]);
            if (check(s))
            {
                ok = false;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}