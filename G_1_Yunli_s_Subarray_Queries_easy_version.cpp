// 2024-09-16 10:52:28
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pii pair<int, int>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPREV(i, k, n) for (int i = n - 1; i >= k; i--)
#define pb push_back
#define mp make_pair
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
        a[i] -= i;
    }
    multiset<int> s;
    map<int, int> m;
    REP(i, 0, k - 1)
    {
        if (m.find(a[i]) != m.end())
        {
            s.erase(s.find(m[a[i]]));
            m[a[i]]++;
            s.insert(m[a[i]]);
        }
        else
        {
            m[a[i]]++;
            s.insert(1);
        }
    }
    vi ans(n - k + 1);
    REP(i, k - 1, n)
    {
        if (m.find(a[i]) != m.end())
        {
            s.erase(s.find(m[a[i]]));
            m[a[i]]++;
            s.insert(m[a[i]]);
        }
        else
        {
            m[a[i]]++;
            s.insert(1);
        }
        ans[i - k + 1] = *s.rbegin();
        s.erase(s.find(m[a[i - k + 1]]));
        m[a[i - k + 1]]--;
        s.insert(m[a[i - k + 1]]);
    }
    REP(i, 0, q)
    {
        int l, r;
        cin >> l >> r;
        cout << k - ans[l - 1] << endl;
    }
    m.clear();
    s.clear();
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}