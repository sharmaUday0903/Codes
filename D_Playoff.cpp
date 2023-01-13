// author : Uday Sharma
// 2022-12-16 20:57:11
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

    string s;
    cin>>s;
    int p =count(s.begin(),s.end(),'0');
    int q =count(s.begin(),s.end(),'1');
    int a=pow(2,p)-1;
    int b=pow(2,q);
    int c=pow(2,n);
    a=c-a;

    REP(i,b,a+1
    )
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
signed main(){
fast;
int t;
t=1;
// cin>>t;
while(t--)
    {
    solve();
    }
}