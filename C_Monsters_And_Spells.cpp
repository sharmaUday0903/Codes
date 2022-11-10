// author : Uday Sharma
// 2022-10-27 19:24:25
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

int f(int n)
{
    return (n * (n + 1)) / 2;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        vi k(n), h(n);
        REP(i, 0, n)
        {
            cin >> k[i];
        }
        REP(i, 0, n)
        {
            cin >> h[i];
        }
        int ans = 0;
        vpi a;
        REP(i, 0, n)
        {
            int cr = k[i];
            int cl = cr - h[i] + 1;
            a.pb({cl, cr});
        }
        sortv(a);
        int l=1,r=0;
        for(auto c:a)
        {
            if (c.f>r)
            {
                ans+=f(r-l+1);
                l=c.f;
                r=c.s;
            }
            else r=max(r,c.s);
            
        }
        ans+=f(r-l+1);
        cout<<ans<<endl;
    }
}