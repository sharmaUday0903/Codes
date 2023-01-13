#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define fast   ios::sync_with_stdio(false); cin.tie(0);
#define pii pair<int,int> 
#define REP(i,k,n) for(int i=k;i<n;i++)
#define REPREV(i,k,n) for(int i=n-1;i>=k;i--)
#define pb push_back
#define mp make_pair
#define vpi vector<pair<int,int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(),v.end())
#define sortrev(v) sort(v.begin(),v.end(),greater<int>())
#define int long long int
#define ub(v,idx,val) upper_bound(v.begin()+idx,v.end(),val)
#define lb(v,idx,val) lower_bound(v.begin()+idx,v.end(),val)

#define vvi vector<vi>
const  double pi=3.14159265358979323846;
const int INF=1e15;
const int MOD=1e9+7;
int rootn(int x,int y)
{
return ceil(log(x)/log(y));
    
}
bool sortbysec(pii &a, pii &b )
{
    return a.s<b.s;
}
bool sortbyfirstdesc(pii &a ,pii &b)
{
    return a.f>b.f;
}
bool sortbysecdesc(pii &a,pii &b)
{
    return a.s>b.s;
}
int power(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y%2)
        {
            res=res*x;
        }
        y=y>>1;
        x=x*x;
    }
    return res;
}
int power(int x,int y,int mod)
{
    int res=1;
     x=x%mod;
    if(x==0)
    return 0;
    while(y)
    {
        if(y%2)
        {
            res=(res*x)%mod;
        }
        y=y>>1;
        x=(x*x)%mod;
    }
    return res;
}
int inversemod(int n,int  mod)
{
      return power(n,mod-2)%MOD;
}
//For solving union of segments from point xl to xr Use segment tree with lazy propogation to store
// number of segements that have point i for leaf and other intermediate nodes for minimum of them
//at last use lazy porpogation to update a segment from xl to xr
const int maxl=5e6+5;
int cnt[maxl]={0};
void solve(){
    int n;
    cin>>n;
    REP(i,0,n)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    vector<int> dp(maxl,0);
    for(int i=0;i<maxl;i++)
    {
        dp[i]=i*cnt[i];
    }
    for(int i=1;i<maxl;i++)
    {
        for(int j=2*i;j<maxl;j+=i)
        cnt[i]+=cnt[j];
    }
    for(int i=maxl;i>=1;i--)
    {
        for(int j=2*i;j<maxl;j+=i)
        {
            dp[i]=max(dp[i],dp[j]+i*(cnt[i]-cnt[j]));
        }
    }
    int ans=dp[1];
    cout<<ans<<"\n";
    

    
}

signed main() {
    fast;
    int t=1;
    // cin>>t;
    while(t--)
    solve();
}