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
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        multiset<int> s;
        REP(i, 1, n + 1)
        {
            s.insert(i);
        }
        vi ans;

        bool u = true;
        REP(i, 0, n)
        {
            if (a[i] <= i)
            {
                u = false;
                break;
            }
            if (a[i] == n)
            {
                ans.pb(n);
                s.erase(n);
                break;
            }
            else
            {
                if (s.find(a[i]) != s.end())
                {

                    ans.pb(a[i]);
                    s.erase(a[i]);
                }
                else
                {
                    auto c = *s.begin();
                    int p = c;
                    ans.pb(p);
                    s.erase(p);
                }
            }
        }
        if (u)
        {
            /* code */
            for (auto c : ans)
            {
                cout << c << " ";
            }
            for (auto c : s)
            {
                cout << c << " ";
            }
        }
        else
            cout << -1;

        cout << endl;
    }
}