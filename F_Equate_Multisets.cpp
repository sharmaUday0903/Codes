// author : Uday Sharma
// 2022-10-29 23:08:42
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
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        multiset<int> m;
        int a[n], b[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            while (a[i] % 2 == 0)
            {
                a[i] /= 2;
            }
            m.insert(a[i]);
        }
        REP(i, 0, n)
        {
            cin >> b[i];
        }
        sort(b, b + n, greater<int>());
        bool ans = true;
        REP(i, 0, n)
        {
        //     for (auto c : m)
        //     {
        //         cout << c << " ";
        //     }
        // cout << endl;
            bool u = true;
            while (b[i] >= 1)
            {
                if (m.find(b[i]) != m.end())
                {
                    m.erase(m.find(b[i]));
                    u = false;
                    break;
                }
                b[i] /= 2;
            }
            if (u)
            {
                ans = false;
                break;
                /* code */
            }
        }
        ans ? cout << "YES\n" : cout << "NO\n";
    }
}