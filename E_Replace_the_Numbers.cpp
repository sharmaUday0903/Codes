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

const int N=5e5+1;

signed main()
{
    fast;
    int t;
    cin >> t;
    vi op(t);
    vi ans,x(t),y(t);
    REP(i, 0, t)
    {
        cin>>op[i]>>x[i];
        if (op[i]==2)
        {
            cin>>y[i];
        }
    }
    vi f(N);
    iota(f.begin(),f.end(),0);
    REPREV(i,0,t)
    {
        if (op[i]==1)
        {
            ans.pb(f[x[i]]);
        }
        else
        {
            f[x[i]]=f[y[i]];
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto c:ans)
    {
        cout<<c<<" "; 
    }
    cout<<endl;
   
}