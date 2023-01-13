// author : Uday Sharma
// 2022-12-15 19:34:49
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
    vi a(n);
    REP(i, 0, n)
    cin >> a[i];
    if (a[n - 1] == 0)
    {
        REP(i, 1, n + 2)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        int cnt = count(a.begin(), a.end(), 0);
        if (cnt == 0)
        {
            cout<<n+1<<" ";
            REP(i,1,n+1)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
        int p = -1;
        REPREV(i, 0, n)
        {
            if (a[i] == 0)
            {
                p = i + 1;
                break;
            }
        }
        REP(i, 1, n + 1)
        {
            if (p == i)
            {
                cout << i << " ";
                cout << n + 1 << " ";
            }
            else
            {
                cout << i << " ";
            }
        }
        cout << endl;
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