// author : Uday Sharma
// 2022-11-26 17:04:31
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
    int n, m;
    cin >> n >> m;
    if (n % m)
    {
        cout << -1 << endl;
    }
    else
    {
        vi v(n);
        REP(i, 0, n)
        v[i] = i + 1;
        v[n - 1] = 1;
        v[0] = m;
        if (m != n)
        {
            v[m - 1] = n;
        }
        REP(idx, 2, (n / 2) + 1)
        {
            if (idx == m)
            {
                int mu = 2 * m;
                while (n % mu != 0 && mu < n)
                {
                    mu += m;
                }
                if (n % mu == 0 && mu < n)
                {
                    swap(v[idx - 1], v[mu - 1]);
                    m = mu;
                }
            }
        }
        for(auto c:v)
        {
            cout<<c<<" ";
        }
        cout<<endl;
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