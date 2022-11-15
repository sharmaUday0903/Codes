// author : Uday Sharma
// 2022-11-09 20:09:32
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
    map<int,int>m;
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    map<int, int> m1, m2;
    bool ans = false;
    REPREV(i, 0, n)
    {
        if (a[i] != a[0])
        {
            m1[a[i]]++;
        }
        else
            break;
    }
    REP(i, 0, n)
    {
        if (a[i] != a[n - 1])
        {
            m2[a[i]]++;
        }
        else
            break;
    }
    REP(i,1,n-1)
    {
        if (a[i]==a[0]&&a[i+1]==a[n-1])
        {
            ans=true;
            
        }
        
    }
    if (m1.size() <= 1 || m2.size() <= 1||m.size()<=2)
    {
        ans = true;
        /* code */
    }
    ans ? cout << "YES\n" : cout << "NO\n";
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