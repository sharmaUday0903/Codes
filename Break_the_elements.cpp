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
        int neg=0;
        int a[n];
        REP(i,0,n)
        {
            cin>>a[i];
            if (a[i]%2!=0)
            {
                neg++;
                /* code */
            }
        }
        if (neg==0)
        {
            cout<<0<<endl;
            /* code */
        }
        else if (neg==n)
        {
            cout<<0<<endl;
            /* code */
        }
        else
        {
            int p = n-neg;
            cout<<p<<endl;
        }
        
        
        
            
    }
}