// author : Uday Sharma
// 2022-12-21 20:24:11
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

const int N = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    map<int, int> m;
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    int num = 1;
    vi ans(n);
    // vi cnt(N, 0);
    map<int,int>cnt;
    REP(i, 0, n)
    {
        if (m[a[i]] == 0)
        {
            ans[i] = num;
            m[a[i]] = num;
            num++;
        }
        else
        {
            if (cnt[a[i]]%a[i] == 0)
            {
                ans[i] = num;
                m[a[i]] = num;
                num++;
            }
            else
            {
                ans[i] = m[a[i]];
            }
        }

        cnt[a[i]]++;
    }
    // cout << cnt[2] << " " << cnt[3] << endl;
    // for(auto c:a)
    // {
    //     cout<<c<<" ";
    // }
    bool u = true;
    for (auto c : cnt)
    {
        if ((c.s % c.f) == 0)
        {
        }
        else
            u = false;
        // cout << c.f << " " << c.s << endl;
    }
    if (!u)
    {
        cout << -1;
    }
    else
        for (auto c : ans)
        {
            cout << c << " ";
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