// author : Uday Sharma
// 2022-11-04 12:48:41
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
    auto Ask = [&](int x)
    {
        cout << "? " << x + 1 << endl;
        int y;
        cin >> y;
        return y;
    };
    vi p(n, -1);
    REP(i, 0, n)
    {
        if (p[i] != -1)
        {
            continue;
        }
        int x = Ask(i);
        vi c(1, x);
        while (true)
        {
            c.pb(Ask(i));
            if (c.back() == c[0])
            {
                c.pop_back();
                break;
            }
        }
        int sz = c.size();
        REP(j, 0, sz)
        {
            p[c[j] - 1] = c[(j + 1) % sz] - 1;
        }
        cout<<"!";
        REP(i,0,n)
        {
            cout<<" "<<p[i]+1;
        }
        cout<<endl;
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