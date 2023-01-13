// author : Uday Sharma
// 2022-12-12 22:46:35
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
    if (n == 1)
    {
        cout << "NO\n";
        return;
    }
    map<string, int> m;
    REP(i, 1, n)
    {
        string a = "";
        a += s[i - 1];
        a += s[i];
        if (m[a] > 0)
        {
            if (i >= 2)
            {
                if (s[i - 2] == s[i - 1] && s[i - 1] == s[i])
                {
                }
                else
                {

                    cout << "YES\n";
                    return;
                }
            }
        }
        m[a]++;
    }
    int cnt = 1;
    int ans = 1;
    REP(i, 1, n)
    {
        if (s[i - 1] == s[i])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    if (ans >= 4)
    {
        cout << "YES\n";
        /* code */
    }
    else
    {
        cout << "NO\n";
    }
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