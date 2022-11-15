// author : Uday Sharma
// 2022-11-06 20:27:04
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
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    bool u = true;
    REP(i, 0, n)
    {
        if (a[i] != b[i])
        {
            cnt++;
            break;
        }
    }
    REP(i, 0, n)
    {
        if (a[i] == b[i])
        {
            cnt++;
            break;
        }
    }
    int pp = count(a.begin(), a.end(), '1');
    int qq = count(b.begin(), b.end(), '1');
    if (cnt == 2)
    {
        cout << "NO\n";
    }
    else
    {
        vpi ans;
        cout << "YES\n";
        if (a[0] == b[0])
        {
            if (pp % 2 == 0)
            {
                REP(i, 0, n)
                {
                    if (a[i] == '1')
                    {
                        ans.pb({i + 1, i + 1});
                    }
                }
            }
            else
            {
                REP(i, 0, n)
                {
                    if (a[i] == '1')
                    {
                        ans.pb({i + 1, i + 1});
                    }
                }
                ans.pb({1, 1});
                ans.pb({2, n});
                ans.pb({1,n});
            }

        }
        else
        {
             if (pp % 2 != 0)
            {
                REP(i, 0, n)
                {
                    if (a[i] == '1')
                    {
                        ans.pb({i + 1, i + 1});
                    }
                }
            }
            else
            {
                REP(i, 0, n)
                {
                    if (a[i] == '1')
                    {
                        ans.pb({i + 1, i + 1});
                    }
                }
                ans.pb({1, 1});
                ans.pb({2, n});
                ans.pb({1,n});
            }

        }
        cout<<ans.size()<<endl;
        for(auto c:ans)
        {
            cout<<c.f<<" "<<c.s<<endl;
        }
        
    }
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