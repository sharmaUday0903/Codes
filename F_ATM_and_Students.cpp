// author : Uday Sharma
// 2022-11-02 09:45:09
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
    int n, s;
    cin >> n >> s;
    vi a(n);
    for (auto &x : a)
        cin >> x;
    vi psums(n + 1, 0);
    REP(i, 0, n)
    {
        psums[i + 1] = psums[i] + a[i];
    }
    vi mins;
    pair<int, int> best = {-1, -1};
    mins.pb({n});
    REPREV(i, 0, n)
    {
        while (!mins.empty() && psums[mins.back()] >= psums[i])
        {
            mins.pop_back();
        }
        mins.pb(i);
        int st = -1;
        int en = mins.size();
        while (st + 1 < en)
        {
            int mid = (st + en) / 2;
            if (s + psums[mins[mid]] - psums[i] < 0)
            {
                st = mid;
            }
            else
            {
                en = mid;
            }
        }
        int goal = (st == -1) ? n : (mins[st] - 1);
        if (goal - i > best.s - best.f)
        {
            best = {i, goal};
        }
    }
        if (best.f == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << best.f + 1 << " " << best.s << endl;
        }
}
signed main()
{
    fast;
    int t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}