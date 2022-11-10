// author : Uday Sharma
// 2022-10-30 15:51:33
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

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, d, mx = 0;
        cin >> n >> d;
        vi v(n), vis(n, 0);
        REP(i, 0, n)
            cin >> v[i];
        REP(i, 0, n)
  
        {
            if (v[i] || vis[i])
            {
                continue;
            }
            int cnt=0;
            int curr=i;
            while (!vis[curr])
            {
                if (v[curr])
                {
                    cnt++;
                }else cnt=0;
                
                mx=max(mx,cnt);
                vis[curr]=1;
                curr+=d;
                curr%=n;
            }
        }
        if (count(vis.begin(),vis.end(),1)!=n)
        {
            cout<<-1<<endl;
        }
        else cout<<mx<<endl;
        

            
    }
}