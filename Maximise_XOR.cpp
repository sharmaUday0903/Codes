// author : Uday Sharma
// 2022-12-10 20:35:53
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
    string a, b;
    cin >> a >> b;
    int n = a.length();
    multiset<char> x, y;
    REP(i, 0, n)
    {
        x.insert(a[i]);
        y.insert(b[i]);
    }
    string ans = "";
    REP(i, 0, n)
    {
        if (x.find('1') != x.end() && y.find('0') != y.end())
        {
            ans += '1';
            x.erase(x.find('1'));
            y.erase(y.find('0'));
        }
        else if (y.find('1') != y.end() && x.find('0') != x.end())
        {
            ans += '1';
            x.erase(x.find('0'));
            y.erase(y.find('1'));
        }
        else ans+='0';
    }
    cout<<ans<<endl;
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