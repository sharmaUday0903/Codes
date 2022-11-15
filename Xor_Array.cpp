// author : Uday Sharma
// 2022-11-09 20:02:32
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
    int n;
    cin>>n;
    int a[n];
    REP(i,0,n)
    {
        cin>>a[i];
    }
    int ans=1;
    int c=(1<<31);
    c--;
    REP(i,0,n)a[i]^=c;
    if (n==1)
    {
    cout<<1<<endl;
    }
    
    REP(i,1,n)
    {
        if (a[i-1]<a[i])
        {
            ans++;
        }
        else break;
    }
    cout<<ans<<endl;
        
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