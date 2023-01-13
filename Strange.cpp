// author : Uday Sharma
// 2022-12-14 19:04:29
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
    int ans=n+1;
    int val=((n+1)*n)-1;
    if (n==2)
    {
        cout<<3<<endl;
        return;
    }
    
    for(int i=2;i<sqrt(n)+1;i++)
    {
        if (n%i==0)
        {
            int p =i;
            int q=n/i;
            // int pp=n+p;
            // int qq=n+q;
            // int g1=p;
            // int g2=q;
            // int l1=(pp*n);
            // l1/=g1;
            // int l2=(qq*n);
            // l2/=g2;
            // int val1=abs(g1-l1);
            // int val2=abs(g2-l2);
            // if (val1<val)
            // {
            //     val=val1;
            //     ans=pp;
            // }
            // if (val2<val)
            // {
            //     val=val2;
            //     ans=qq;
            // }
            ans=n+q;
            break;
        }
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