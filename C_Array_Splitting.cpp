#include<bits/stdc++.h>
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define REP(i,k,n) for(int i=k;i<n;i++)
#define REPREV(i,k,n) for(int i=n-1;i>=k;i--)
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(),v.end())
#define sortrev(v) sort(v.begin(),v.end(),greater<int>())
#define int long long int

signed main(){
fast;
    int n,k;
    cin>>n>>k;
    int a[n];
    REP(i,0,n)
    {
        cin>>a[i];
    }
    int p = n-k;
    int ans1=a[p]-a[0];
    int ans2=a[n-1]-a[k-1];
    int ans=min(ans1,ans2);
    vi v;
    REP(i,0,n-1)
    {
        v.pb(a[i+1]-a[i]);
    }
    sortv(v);
    REP(i,0,k-1)
    {
        v.pop_back();
    }
    int sum=0;
    REP(i,0,v.size())
    {
        sum+=v[i];
    }
    ans=min(sum,ans);
    cout<<ans<<endl;
}