
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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(m);
    REP(i, 0, m)
    {

        cin >> a[i];
    }
    int p = *max_element(a.begin(),a.end());
    int q=count(a.begin(),a.end(),p);

    if (n-p-(q-1)<(k-1)*(p-1))
    {
        cout<<"NO\n";
    }
    else cout<<"YES\n";
    
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