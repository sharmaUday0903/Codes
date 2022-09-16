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
bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}
signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        vpi v;
        vector<bool> qualify(n, false);
        int a[n], b[n];
        map<int, int> m;
        REP(i, 0, n)
        {
            cin >> a[i];
            m[a[i]] = i;
        }
        REP(i, 0, n)
        {
            cin >> b[i];
        }
        REP(i, 0, n)
        {
            v.pb(mp(a[i], b[i]));
        }

        int ans = 0;
        sortv(v);

        set<int> s;
        REPREV(i, 0, n)
        {
            if (qualify[m[v[i].f]] == false)
            {
                if (i == n - 1)
                {
                    ans++;
                    qualify[m[v[i].f]] = true;
                }
                else
                {
                    auto it = s.rbegin();
                    int p = *it;
                    if (p < v[i].s)
                    {
                        ans++;
                        qualify[m[v[i].f]] = true;
                    }
                }
            }
            s.insert(v[i].s);
        }
        sort(v.begin(), v.end(), sortbysec);
        set<int> ss;
        REPREV(i, 0, n)
        {
            if (qualify[m[v[i].f]] == false)
            {
                if (i == n - 1)
                {
                    ans++;
                    qualify[m[v[i].f]] = true;
                }
                else
                {
                    auto it = ss.rbegin();
                    int p = *it;
                    if (p < v[i].f)
                    {
                        ans++;
                        qualify[m[v[i].f]] = true;
                    }
                }
            }
            ss.insert(v[i].f);
        }
        cout<<ans<<endl;
    }
}