// author : Uday Sharma
// 2022-12-17 15:40:29
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
    int n,m;
    cin>>n>>m;
    if (n==m&&m==0)
    {
        cout<<0<<endl;
        /* code */
    }
    else if (n==m)
    {
        cout<<1<<endl;
        /* code */
    }
    else if ((max(m,n)-min(m,n))%2!=0)
    {
        cout<<-1<<endl;
        /* code */
    }
    else cout<<2<<endl;
    
    
    
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