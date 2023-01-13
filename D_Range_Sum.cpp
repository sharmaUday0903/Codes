// author : Uday Sharma
// 2022-11-26 17:14:49
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
    if (n % 2)
    {
        vi v;
        int p = (n / 2)+1;
        while (v.size() != n)
        {
            v.pb(p+2);
            p++;
        }
        v[0]--;
        v[n-1]++;
        v[n-2]++;
        for (auto c : v)
            cout << c << " ";
            cout<<endl;
    }
    else
    {
        int idx = n - 1;
        int cnt = 0;
        while (true)
        {
            cout << idx << " ";
            idx--;
            cnt += 2;
            if (cnt == n)
            {
                break;
            }
        }
        idx = n + 1;
        cnt = 0;
        while (true)
        {
            cout << idx << " ";
            idx++;
            cnt += 2;
            if (cnt == n)
            {
                break;
            }
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