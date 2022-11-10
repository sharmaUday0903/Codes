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
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int m;
        cin >> m;
        int sum = 0;
        int b[m];
        REP(i, 0, m)
        {
            cin >> b[i];
            if (b[i] > 0)
            {
                sum += b[i];
            }
        }
        
        int pref[n];
        pref[0] = a[0];
        int suff[n];
        suff[n - 1] = a[n - 1];
        REP(i, 1, n)
        {
            pref[i] = pref[i - 1] + a[i];
        }
        REPREV(i, 0, n - 1)
        {
            suff[i] = suff[i + 1] + a[i];
        }
        int ans1=*max_element(pref,pref+n);
        int ans2=*max_element(suff,suff+n);
        int ans=max(ans1,ans2);
        ans+=sum;
        cout<<ans<<endl;
    }
}