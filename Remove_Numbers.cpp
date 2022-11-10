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
#define int long long int

signed main()
{
    fast;
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    multiset<int> s;
    REP(i, 0, n)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    REP(i, 0, m)
    {
        cin >> b[i];
    }
    REP(i, 0, m)
    {
        int p = 0, q = 0;
        // REP(j, 0, n)
        // {
        //     if (a[j] % b[i] == 0)
        //     {
        //         p += a[j];
        //     }
        //     else
        //         q += a[j];
        // }
        for (auto c : s)
        {
            if (c % b[i] == 0)
            {
                p += c;
            }
            else
            {
                q += c;
            }
        }
        if (p >= q)
        {
            if (i % 2 != 0)
            {
                REP(j, 0, n)
                {
                    if (a[j] % b[i] == 0)
                    {
                        if (s.find(a[j]) != s.end())
                        {
                            s.erase(s.find(a[j]));
                        }
                    }
                }
            }
            else
            {
                REP(j, 0, n)
                {
                    if (a[j] % b[i] != 0)
                    {
                        if (s.find(a[j]) != s.end())
                        {
                            s.erase(s.find(a[j]));
                        }
                    }
                }
            }
        }
        else
        {
            if (i % 2 != 0)
            {
                REP(j, 0, n)
                {
                    if (a[j] % b[i] == 0)
                    {
                        if (s.find(a[j]) != s.end())
                        {
                            s.erase(s.find(a[j]));
                        }
                    }
                }
            }
            else
            {
                REP(j, 0, n)
                {
                    if (a[j] % b[i] != 0)
                    {
                        if (s.find(a[j]) != s.end())
                        {
                            s.erase(s.find(a[j]));
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (auto c : s)
    {
        ans += c;
    }
    cout << ans << endl;
}