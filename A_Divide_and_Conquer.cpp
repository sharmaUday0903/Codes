// author : Uday Sharma
// 2022-12-15 20:05:40
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
    int sum=0;
    vi a(n);
    REP(i,0,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if (sum%2==0)
    {
        cout<<0<<endl;
        /* code */
    }
    else
    {
        int ans=inf;
        REP(i,0,n)
        {
            int cnt=0;
            if (a[i]%2==0)
            {
                while (a[i]%2==0)
                {
                    a[i]/=2;
                    cnt++;
                }
                
            }
            else
            {
                while (a[i]%2!=0)
                {
                    a[i]/=2;
                    cnt++;
                    /* code */
                }
                
            }
            
            ans=min(ans,cnt);
            
        }
        cout<<ans<<endl;
    }
    
    
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