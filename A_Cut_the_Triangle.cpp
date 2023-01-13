// author : Uday Sharma
// 2022-12-16 20:07:41
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
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    vi a1,a2;
   a1.pb(x1);
   a1.pb(x2);
   a1.pb(x3);
   a2.pb(y1);
   a2.pb(y2);
   a2.pb(y3);
    sortv(a1);
    sortv(a2);
    bool u=true;
    if ((a1[0]==a1[1]||a1[1]==a1[2])&&(a2[0]==a2[1]||a2[1]==a2[2]))
    {
    u=false;
    }
   
    if (!u)
    {
        cout << "NO\n";
        /* code */
    }
    else
        cout << "YES\n";
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