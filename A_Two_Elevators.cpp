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
        int x,y,z;
        cin>>x>>y>>z;
        int a1=abs(x-1);
        int a2 = abs(y-z)+abs(z-1);
        if (a1<a2)
        {
            cout<<1<<endl;
            /* code */
        }
        else if (a1==a2)
        {
            cout<<3<<endl;
            /* code */
        }
        else
        {
            cout<<2<<endl;
        }
        
        
        
    }
}