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
        int a[n], b[n], diff[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        REP(i, 0, n)
        {
            cin >> b[i];
            diff[i] = b[i] - a[i];
        }
        sort(diff, diff + n);
        deque<int> q;
        REP(i, 0, n)
        {
            q.pb(diff[i]);
        }
        int ans = 0;
        while (q.size() >= 2)
        {
            int p = q.front() + q.back();
            if (p >= 0)
            {
                ans++;
                q.pop_back();
                q.pop_front();
            }
            else
            {
                q.pop_front();
            }
        }
        cout<<ans<<endl;
    }
}