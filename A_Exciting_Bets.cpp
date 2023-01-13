// author : Uday Sharma
// 2022-12-15 18:42:08
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
#define inf 1000000000000000005
#define int long long int

void solve()
{
    int a,b;
    cin>>a>>b;
    int ans1=max(a,b)-min(a,b);
    if (ans1==0)
    {
        cout<<0<<" "<<0<<endl;
        return;
    }
    
    int p = min(a,b)%ans1;
    int ans2=min(p,ans1-p);
    cout<<ans1<<" "<<ans2<<endl;
}
signed main(){
fast;
int t;
t=1;
cin>>t;
while(t--)
    {
    solve();
    }
}