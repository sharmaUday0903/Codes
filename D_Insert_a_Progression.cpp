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
        int n,x;
        cin >> n>>x;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int ans = 0;
        REP(i, 0, n - 1)
        {
            ans += abs(a[i] - a[i + 1]);
        }
        int mn=1e9;
        mn=min(mn,a[0]-1);
        mn=min(mn,a[n-1]-1);
        REP(i,0,n)
        {
            mn=min(mn,2*(a[i]-1));
        }
        ans+=mn;
        int mx=*max_element(a,a+n);
        if (mx<x)
        {
            int mn=1e9;
            mn=min(mn,x-a[0]);
            mn=min(mn,x-a[n-1]);
            REP(i,0,n)
            {
                mn=min(mn,2*(x-a[i]));
            }
            ans+=mn;
        }
        cout<<ans<<endl;
        
    }
}