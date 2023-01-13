// author : Uday Sharma
// 2022-12-14 21:55:16
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
    map<int, int> m;
    map<int, int> mm;
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    REP(i, 0, n)
    {
        int x = a[i];
        int cnt = 1;
        while (x)
        {
            int p = x % 2;
            x /= 2;
            if (p == 1)
            {
                m[cnt]++;
                mm[cnt]++;
            }
            cnt++;
        }
    }
    for (auto c : m)
    {
        if (c.s == 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    int leftx = 0;

    REP(i, 0, n)
    {
        int x = a[i];
        int cnt = 1;
        while (x)
        {
            int p = x % 2;
            x /= 2;
            if (p == 1)
            {
                /* code */

                if (m[cnt] == 1)
                {
                    leftx = i + 1;
                    break;
                }
                else
                {
                    m[cnt]--;
                }
            }
            cnt++;
        }
        // for (auto c : m)
        // {
        //     cout << c.s << " ";
        // }
        // cout << endl;
        if (leftx > 0)
        {
            break;
        }
    }
    // cout << leftx << endl;

    int rightx = 0;

    REPREV(i, 0, n)
    {
        int x = a[i];
        int cnt = 1;
        while (x)
        {
            int p = x % 2;
            x /= 2;
            if (p == 1)
            {
                /* code */

                if (mm[cnt] == 1)
                {
                    rightx = i + 1;
                    break;
                }
                else
                {
                    mm[cnt]--;
                }
            }
            cnt++;
        }
        // for (auto c : m)
        // {
        //     cout << c.s << " ";
        // }
        // cout << endl;
        if (rightx > 0)
        {
            break;
        }
    }
    cout<<leftx<<" "<<rightx<<endl;
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