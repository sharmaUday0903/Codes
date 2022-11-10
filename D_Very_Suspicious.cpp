// author : Uday Sharma
// 2022-11-03 22:56:12
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

    int num;
bool check(int n)
{
    int x = n / 3;
    int y = n / 3;
    int z = n / 3;
    if (n % 3)
    {
        x++;
    }
     if (n % 3 == 2)
    {
        y++;
    }
    int tr = 2 * (x * y + y * z + z * x);
    return tr >= num;
}

void solve()
{
    cin >> num;
    int l = 1, r = 1e6;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
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