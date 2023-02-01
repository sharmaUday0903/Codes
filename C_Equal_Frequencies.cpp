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
#define vvi vector<vi>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int
const int MOD = 1e9 + 7;


void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zero = 0;
    vector<int> dp(26, zero);
    for (auto c : s)
    {
        dp[c - 'a']++;
    }
    int ans = INT_MAX;
    vpi v;
    REP(i, 0, 26)
    {
        int iii = i;
        v.pb(mp(dp[i], iii));
    }
    sortrev(dp);
    int cnt = 0;
    REP(i, 1, 27)
    {
        if (n % i == 0 && n >= i)
        {
            int tempans = 0;
            int check = n / i;
            REP(j, 0, i)
            {
                int c = check - dp[j];
                if (c > 0)
                    tempans += c;
            }
            // ans = min(ans, tempans);
            if (ans >= tempans)
            {
                ans = min(ans, tempans);
                cnt = i;
            }
        }
    }
    sortv(v);
    int cntnum = n / cnt;
    set<char> ss;
    REPREV(i, v.size() - cnt, v.size())
    ss.insert(v[i].s + 'a');

    cout << ans << endl;
    
    multiset<char> m;
    for (auto c : ss)
    {
        REP(k, 0, cntnum)
        {
            m.insert(c);
        }
    }
    for (auto c : s)
        if (m.find(c) != m.end())
        {
            m.erase(m.find(c));
        }
    map<int, int> check;
    for (auto c : s)
    {
        if (check[c] == cntnum || ss.find(c) == ss.end())
        {
            cout << *m.begin();
            m.erase(m.find(*m.begin()));
        }
        else
            cout << c;
        check[c]++;
    }
    cout << endl;
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