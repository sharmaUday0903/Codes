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

signed main()
{
    fast;
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    REP(i, 0, m)
    {
        cin >> b[i];
    }
    vi v;
    int cnt = 0;
    REP(i, 0, n - 1)
    {
        v.pb(a[i + 1] - a[i]);
    }
    REP(i, 0, v.size())
    {
        cnt = __gcd(cnt, v[i]);
    }
    int p = *min_element(a, a + n);
    REP(i,0,m)
    {
        int pp=p+b[i];
        pp=__gcd(cnt,pp);
        cout<<abs(pp)<<" ";
    }
    cout<<endl;
}