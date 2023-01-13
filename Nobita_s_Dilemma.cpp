// author : Uday Sharma
// 2022-12-16 13:36:59
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
    int a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    int a1=abs(a*(d-h)+c*(h-b)+g*(b-d));
    int a2=abs(c*(f-h)+e*(h-d)+g*(d-f));
    int a3=abs(a*(f-h)+e*(h-b)+g*(b-f));
    int area=abs(a*(d-f)+c*(f-b)+e*(b-d));
    if (area==a1+a2+a3)
    {
        cout<<"True\n";
    }
    else cout<<"False\n";
    
    
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