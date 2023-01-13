// author : Uday Sharma
// 2022-12-14 20:15:48
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
    int p = count(s.begin(), s.end(), '0');
    int q = count(s.begin(), s.end(), '1');
    if (p == 0 || q == 0)
    {
        cout << -1 << endl;
        return;
    }
    vi ans;
    if (p >= n)
    {
        int cnt = 0;
        REP(i, 0, 2 * n)
        {
            if (s[i] == '0')
            {
                ans.pb(i + 1);
                cnt++;
                if (cnt == n)
                {
                    break;
                }
            }
        }
    }
    else
    {
        int cnt=0;
        REP(i, 0, 2 * n)
        {
            if (s[i] == '1')
            {
                ans.pb(i + 1);
                cnt++;
                if (cnt == n)
                {
                    break;
                }
            }
        }
    }
    for (auto c:ans)
    {
        cout<<c<<" ";
    }
    cout<<endl;
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