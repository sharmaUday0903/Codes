#include <bits/stdc++.h>
using namespace std;

#define MAX INT_MAX
#define MIN INT_MIN
#define ll long long int
#define nline "\n"
#define BIG 998244353
#define MOD 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<ll,ll>
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define vpii vector<pii>
#define ff first
#define ss second
#define mkp make_pair
#define pb emplace_back
void solve()
{
    ll n;
    cin>>n;
    if(n==2){
        cout<<"-1\n";
        return;
    }
    int on=1,ze=n-1;
    for(int i=0; i<n-1 ;i++){
        string s="";
        int j=0;
        while(j++<on)s+='1';
        j=0;
        while(j++<ze)s+='0';
        on++, ze--;
        cout<<s<<nline;
    }
    for(int i=0; i<n; i++){
        if(i&1)cout<<'0';
        else cout<<'1';
    }
    cout<<nline;
}
int main()
{
    fast_io;

    int t=1;
    cin>>t;
    while(t--) 
        solve();
}