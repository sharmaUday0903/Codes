// author : Uday Sharma
// 2022-12-15 23:23:47
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
    vector<string>v;
    REP(i,0,n)
    {
        string x;
        cin>>x;
        v.pb(x);
    }
    REP(i,0,n-1)
    {
        string x;
        cin>>x;
        v.pb(x);
    }
    REP(i,0,m)
    {
        int x=0;
        for(auto c:v)
        {
            x=x^(int)c[i];
        }
        cout<<(char)x;
    }
    cout<<"\n"<<flush;
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