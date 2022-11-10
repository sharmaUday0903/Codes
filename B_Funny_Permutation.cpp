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
        if (n%2==0)
        {
            vi v;
            REP(i,0,n)
            {
                v.pb(i+1);
            }
            sortrev(v);
            for(auto c:v)
            {
                cout<<c<<" ";
            }
            cout<<endl;
            /* code */
        }
        else if (n==3)
        {
            cout<<-1<<endl;
            /* code */
        }
        else
        {
            cout<<n<<" "<<n-1<<" ";
            REP(i,1,n-1)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        
                
    }
}