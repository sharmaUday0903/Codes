// author : Uday Sharma
// 2022-11-10 22:37:44
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
    string s;
    cin >> s;
    int ans = 0;
    int lst1 = -1, lstz = -1;

    REP(i, 0, s.size())
    {
        int c = s[i] - '0';
        if (c == 0 || c == 1)
        {
            if (c^(i%2)==0)
            {
                lstz=i;
            }
            else lst1=i;
            
        }
        int mn = min(lstz, lst1);
        ans += i - mn;
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