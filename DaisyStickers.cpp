// author : Uday Sharma
// 2022-12-16 12:18:09
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
    int w, l, n;
    cin >> w >> l >> n;
    int left = 1;
    int right = max(l,w)*n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int p = mid / l;
        int q = mid / w;
        // int r = p * q;
        if ((n) > q*p)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << right + 1 << endl;
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