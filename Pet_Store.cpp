// author : Uday Sharma
// 2022-12-28 20:01:09
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
    vi a(n);
    map<int,int>m;
    REP(i,0,n)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    bool ans=true;
    for(auto c:m)
    {
        if (c.s%2==1)
        {
            ans=false;
            /* code */
        }
        
    }
    ans?cout<<"YES\n":cout<<"NO\n";
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