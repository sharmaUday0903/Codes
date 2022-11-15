// author : Uday Sharma
// 2022-11-09 21:20:23
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

bool isDivisible(int a, int b)
{
    if (b == 1)
        return true;
    int gcd = __gcd(a, b);
    if (gcd == 1)
        return false;
    return isDivisible(a, b / gcd);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    if (isDivisible(n,m))
    {cout<<"YES\n";
        /* code */
    }
    else cout<<"NO\n";
    

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