// author : Uday Sharma
// 2022-12-19 16:49:04
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
    int a, b;
    cin >> a >> b;
    vi v;
    v.pb(b);
    while (b > 0 && b != a)
    {
        if (b % 2 == 0)
        {
            b /= 2;
        }
        else
        {
            if (b % 10 == 1)
            {
                b /= 10;
            }
            else
            {
                break;
            }
        }
        v.pb(b);
    }
    reverse(v.begin(),v.end());
    a == b ? cout << "YES\n" : cout << "NO\n";
    if (a==b)
    {cout<<v.size()<<endl;
    for(auto c:v)cout<<c<<" ";cout<<endl;
        /* code */
    }
    
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}