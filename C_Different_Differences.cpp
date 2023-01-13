// author : Uday Sharma
// 2022-12-18 20:19:38
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
    int p = n - 1;
    int q = (p * (p + 1)) / 2;
    q++;
    if (m >= q)
    {
        int val = 1;
        int cnt = 1;
        REP(i, 0, n)
        {
            cout << val << " ";
            val += cnt;
            cnt++;
        }
        cout << endl;
    }
    else
    {
        vi ans;
        int val = m;
        int index=0;
        REPREV(i, 0, n)
        {
            int y = (i * (i + 1)) / 2;
            y++;
            if (val >= y)
            {
                index=i+1;
                break;
            }
            else
            {
                ans.pb(val);
                val--;
            }
        }
        val=1;
         int cnt = 1;
        REP(i, 0, index)
        {
            ans.pb(val);
            val += cnt;
            cnt++;
        }
        sortv(ans);
        for(auto c:ans)
        {
            cout<<c<<" ";
        }
        cout << endl;
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