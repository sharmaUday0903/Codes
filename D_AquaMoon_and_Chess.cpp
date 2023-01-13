// author : Uday Sharma
// 2022-12-15 23:34:53
#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPREV(i, k, n) for (int i = n - 1; i >= k; i--)
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define inf 1000000000000000005
#define int long long int


const int maxl=2e5+5;
const int MOD=998244353;

int power(int x,int y)
{
    if(y==0)
    return 1;
    if(y%2==0)
    return power(x,y/2)%MOD*power(x,y/2)%MOD;
    else
    return x%MOD*power(x,y/2)%MOD*power(x,y/2)%MOD;
}

int fact[maxl];
void inifact()
{
    fact[0]=1;
    fact[1]=1;
    REP(i,2,maxl)
    {
        fact[i]=i*fact[i-1];
        fact[i]%=MOD;
    }
}
int inversemod(int n,int  r)
{
      return power(n,r-2);
}
int ncr(int n,int r)
{
    if(n<r)
    return 0;
    if(r==0)
    return 1;
    if(n==r)
    return 1;
    return (fact[n]%MOD*inversemod(fact[r],MOD)%MOD)%MOD*inversemod(fact[n-r],MOD)%MOD;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = 0;
    REP(i, 0, n - 1)
    {
        if (s[i] == s[i + 1] && s[i] == '1')
        {
            m++;
            i++;
        }
    }
    int x=count(s.begin(),s.end(),'0');
    int tot=m+x;
       cout<<ncr(tot,m)<<"\n";


}

signed main()
{
    fast;
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}