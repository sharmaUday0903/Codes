// author : Uday Sharma
// 2022-12-31 12:26:00
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
    int n, k;
    cin >> n >> k;
    set<int> s;
    REP(i, 1, n + 1)
    {
        s.insert(i);
    }
    while (!s.empty())
    {
        auto c = *s.rbegin();
        cout << c << " ";
        s.erase(c);
        if (!s.empty())
        {
            auto c = *s.begin();
            cout << c << " ";
            s.erase(c);
        }
    }

    cout << endl;
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