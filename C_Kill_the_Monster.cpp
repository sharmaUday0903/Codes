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
        int hc, dc;
        cin >> hc >> dc;
        int hm, dm;
        cin >> hm >> dm;
        int k, w, a;
        cin >> k >> w >> a;
        bool u = false;
        REP(i, 0, k + 1)
        {
            int p = i;
            int q = k - i;
            int dcc = dc + (w * p);
            int hcc = hc + (a * q);
            int ans1, ans2;
            if (hm%dcc == 0)
            {
                ans1 = hm / dcc;
            }
            else
            {
                ans1 = (hm / dcc) + 1;
            }
            if (hcc%dm==0)
            {
                ans2=hcc/dm;
            }
            else
            {
                ans2=(hcc/dm)+1;
            }
            if (ans1<=ans2)
            {
                u=true;
                break;
            }
        }
        u?cout<<"YES\n":cout<<"NO\n";
            
            
            
    }
}