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
        map<int, int> m;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        sort(a, a + n);
        vi ans(n + 1, -1);
        ans[0] = m[0];
        int sum = 0;
        vi v;
        REP(i,0,m[0]-1)
        {
            v.pb(0);
        }
        REP(i, 0, n)
        {
            if (a[i] > i)
            {
                break;
            }
            ans[i + 1] = sum + m[i + 1];
            while (m[i + 1]--)
            {
                v.pb(i + 1);
            }
            if (!v.empty())
            {
                sum += i + 1 - v.back();
                v.pop_back();
            }
        }

        for (auto c : ans)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}