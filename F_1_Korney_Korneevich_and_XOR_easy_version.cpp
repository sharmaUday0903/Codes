// author : Uday Sharma
// 2022-10-31 01:54:15
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

signed main()
{
    fast;
    int n;
    cin >> n;
    int a[n + 1];
    REP(i, 1, n + 1)
    {
        cin >> a[i];
    }
    vi ans;
    ans.pb(0);
    vi mn(520, inf);
    mn[0] = 0;
    REP(i, 1, n + 1)
    {
        REP(j, 0, 514)
        {
            if (mn[j] < a[i])
            {
                mn[(j ^ a[i])] = min(mn[(j ^ a[i])], a[i]);
            }
        }
    }
    REP(i, 1, 515)
    {
        if (mn[i] != inf)
        {
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    for (auto c : ans)
    {
        cout << c << " ";
    }
    cout << endl;
}