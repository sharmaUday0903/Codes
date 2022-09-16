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

struct UF
{
    int n;
    vi par;
    UF(int p) : n(p)
    {
        REP(i, 0, n)
        {
            par.pb(i);
        }
    }
    int find(int a)
    {
        if (a != par[a])
        {
            par[a] = find(par[a]);
        }
        return par[a];
    }
    bool join(int a, int b)
    {
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};

signed main()
{
    fast;
    int n, d;
    cin >> n >> d;
    UF uf(n);
    int ex = 0;
    REP(i, 1, d + 1)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (!uf.join(x, y))
        {
            ex++;
        }
        vi csz(n, 0);
        REP(j, 0, n)
        {
            csz[uf.find(j)] += 1;
        }
        // sortv(csz);
        sort(csz.rbegin(),csz.rend());
        int ans=0;
        REP(j,0,n)
        {
            if (j<=ex)
            {
                ans+=csz[j];
            }
            
        }
        cout<<ans-1<<endl;

    }
}