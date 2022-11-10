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
    int t;
    cin>>t;
    REP(i,0,t)
    {
        int n;
        cin>>n;
        int a[n];
        REP(i,0,n)
        {
            cin>>a[i];
        }
        bool u =true;
        int ans=0;
        int cnt=INT64_MAX;
        REP(i,0,n/2)
        {
            int p = a[n-1-i];
            int q=a[i];
            int diff=p-q;
            if (diff==0)
            {
                cnt=0;
            }
            else if (diff<0)
            {
                u=false;
                /* code */
            }
            else
            {

                ans=max(ans,diff);
                if (cnt<diff)
                {
                    u=false;
                    break;
                }
                cnt=diff;
                
            }
            
        }if (u)
        {
            cout<<ans<<endl;
            /* code */
        }
        else cout<<-1<<endl;
        
            
            
    }
}