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
        int n, k;
        cin >> n >> k;
        set<int> s;
        map<int, int> m;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        REP(i, 1, 2 * n + 1)
        {
            if (m[i] == 0)
            {
                s.insert(i);
            }
        }
        int mx=*max_element(a,a+n);
        int ans1 = 0;
        if (s.find(2 * n) != s.end())
        {
            k--;
            s.erase(2 * n);
        }
        REP(i,0,k)
        {
            auto c=*s.begin();
            int p = c;
            int q = 2*n-p;
            ans1+=q;
            s.erase(p);
        }
        int ans2=0;
        REP(i,0,k)
        {
            auto c=*s.begin();
            int p =c;
            int q = mx-p;
            int zero=0;
            ans2+=max(q,zero);
        }
        int ans=max(ans1,ans2);
        cout<<ans<<endl;

    }
}