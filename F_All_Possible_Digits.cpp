// author : Uday Sharma
// 2022-11-20 18:55:43
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
    int n, p;
    cin >> n >> p;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    set<int> s;
    REP(i, 0, n)
    {
        s.insert(a[i]);
    }
    a.push_back(0);
    int x = 0;
    while (x < a[0] && s.count(x))
    {
        x++;
    }
    int ans = 0;
    if (x == a[0])
    {
        x = p - 1;
        while (x > a[0] && s.count(x))
        {
            x--;
        }
        ans = x - a[0];
    }
    else
    {
        x = a[0];
        ans = p - a[0];
        a[0]=0;
        a[1]++;
        REP(i,1,n)
        {
            if (a[i]==p)
            {
                a[i]-=p;
                a[i+1]++;
            }
        }
            REP(i,0,n+1)
            {
                s.insert(a[i]);
            }
             while (x > 0 && s.count(x)) {
            x--;
        }
        ans += x;
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