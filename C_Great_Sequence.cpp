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
        int n, x;
        cin >> n >> x;
        multiset<int> s;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        int ans = 0;
        while (!s.empty())
        {
            auto c = *s.begin();
            int p = c;
            int q = p * x;
            if (s.find(q) != s.end())
            {
                s.erase(s.find(p));
                s.erase(s.find(q));
            }
            else
            {
                ans++;
                s.erase(s.find(p));
            }
        }
        cout<<ans<<endl;
    }
}