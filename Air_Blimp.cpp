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
        int n, x, y;
        cin >> n >> x >> y;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int mx = *max_element(a, a + n);
        int ans = 0;
        if (mx % y == 0)
        {
            ans = mx / y;
        }
        else
        {
            ans = (mx / y) + 1;
        }
       
            int m = 0;
            int ans1 = 0;
            REPREV(i, 0, n)
            {
                int p = a[i] - m;
                if (p > 0)
                {
                    /* code */
                    int q = p / x;
                    if (p % x != 0)
                    {
                        q++;
                    }
                    m+=(y*q);
                    ans1+=q;
                }
            }
            int ans2=min(ans,ans1);
            cout<<ans2<<endl;
        
    }
}