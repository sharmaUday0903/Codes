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
    int n,x;
    cin>>n>>x;
    int a[n];
    vector<int>c(x+1,0);
    REP(i,0,n)
    {
        cin>>a[i];
        c[a[i]]++;
    }
    int ans=0;
    REP(i,1,x)
    {
        if (c[i]%(i+1)==0)
        {
            c[i+1]+=(c[i]/(i+1));
        }
        else
        {
            ans=1;
            break;
        }
    }
    ans==0?cout<<"Yes\n":cout<<"No\n";
        
        
}