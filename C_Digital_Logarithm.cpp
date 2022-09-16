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
        int a[n], b[n];
        multiset<int> m1, m2;
        REP(i, 0, n)
        {
            cin >> a[i];
            m1.insert(a[i]);
        }
        REP(i, 0, n)
        {
            cin >> b[i];
            m2.insert(b[i]);
        }
        int ans = 0;
        while (m1.size())
        {
            int x = *m1.rbegin();
            int y = *m2.rbegin();
            m1.erase(m1.find(x));
            m2.erase(m2.find(y));
            if (x > y)
            {
                m1.insert((int)to_string(x).size());
                m2.insert(y);
                ans++;
            }
            else if (x < y)
            {
                m2.insert((int)to_string(y).size());
                m1.insert(x);
                ans++;
                /* code */
            }
        }
        cout<<ans<<endl;
    }
}