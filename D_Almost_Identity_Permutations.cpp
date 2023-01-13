// author : Uday Sharma
// 2022-12-18 15:04:54
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
    int n,k;
	cin >> n >> k;
	int ans = 0;
if(k > 1) ans += n * (n - 1) / 2;
	if(k > 2) ans += n * (n - 1) * (n - 2) / 6 * 2;
	if(k > 3) ans += n * (n - 1) * (n - 2) * (n - 3) / 24 * 9;
	cout << ans + 1;
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