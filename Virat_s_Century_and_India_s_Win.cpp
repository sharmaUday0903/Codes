// 2023-11-26 12:06:41
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pii pair<int, int>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPREV(i, k, n) for (int i = n - 1; i >= k; i--)
#define pb push_back
#define mp make_pair
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int
#define ub(v, idx, val) upper_bound(v.begin() + idx, v.end(), val)
#define lb(v, idx, val) lower_bound(v.begin() + idx, v.end(), val)

#define vvi vector<vi>
const double pi = 3.14159265358979323846;
const int INF = 1e15;
const int MOD = 1e9 + 7;
int rootn(int x, int y)
{
    return ceil(log(x) / log(y));
}
bool sortbysec(pii &a, pii &b)
{
    return a.s < b.s;
}
bool sortbyfirstdesc(pii &a, pii &b)
{
    return a.f > b.f;
}
bool sortbysecdesc(pii &a, pii &b)
{
    return a.s > b.s;
}
int power(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y % 2)
        {
            res = res * x;
        }
        y = y >> 1;
        x = x * x;
    }
    return res;
}
int power(int x, int y, int mod)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y)
    {
        if (y % 2)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
int inversemod(int n, int mod)
{
    return power(n, mod - 2, mod) % MOD;
}
// For solving union of segments from point xl to xr Use segment tree with lazy propogation to store
//  number of segements that have point i for leaf and other intermediate nodes for minimum of them
// at last use lazy porpogation to update a segment from xl to xr
const int maxl = 2e5 + 5;
bool isprime[maxl];
int fact[maxl];
void sieve()
{
    memset(isprime, true, sizeof(isprime));

    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i < maxl; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j < maxl; j += i)
                isprime[j] = false;
        }
    }
}
void inifact()
{
    fact[0] = 1;
    fact[1] = 1;
    REP(i, 2, maxl)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }
}

void solve()
{
    int n, b, w, x;
    cin >> n >> b >> w >> x;
    int dp[151][61][11][151][2];
    x = 100-x;
    dp[n][b][w][x][1] = 1;
    int prob = inversemod(6,MOD);
    for(int i = n; i>0; i--){
        for(int j = b; b>0; b--){
            for(int k = w; k<10; k++){
                for(int l = x; l>=0; l--){

                    if((j-1)%6!=0){

                        dp[i-1][j-1][k][max((int)0,l-1)][0] = dp[i][j][k][l][1]*prob;
                        dp[i-1][j-1][k][max((int)0,l-1)][0] %= MOD;

                        dp[max((int)0,i-2)][j-1][k][max((int)0,l-2)][0] += dp[i][j][k][l][0]*prob;
                        dp[max((int)0,i-2)][j-1][k][max((int)0,l-2)][0] %= MOD;

                        dp[max((int)0,i-3)][j-1][k][max((int)0,l-3)][0] += dp[i][j][k][l][1]*prob;
                        dp[max((int)0,i-3)][j-1][k][max((int)0,l-3)][0] %= MOD;

                        dp[max((int)0,i-4)][j-1][k][max((int)0,l-4)][0] += dp[i][j][k][l][0]*prob;
                        dp[max((int)0,i-4)][j-1][k][max((int)0,l-4)][0] %= MOD;

                        dp[max((int)0,i-6)][j-1][k][max((int)0,l-6)][0] += dp[i][j][k][l][0]*prob;
                        dp[max((int)0,i-6)][j-1][k][max((int)0,l-6)][0] %= MOD;

                        dp[max((int)0,i)][j-1][k-1][max((int)0,l)][0] = dp[i][j][k][l][0]*prob;
                        dp[max((int)0,i)][j-1][k-1][max((int)0,l)][0] %= MOD;

                        dp[i-1][j-1][k][max((int)0,l-1)][1] = dp[i][j][k][l][0]*prob;
                        dp[i-1][j-1][k][max((int)0,l-1)][1] %= MOD;

                        dp[max((int)0,i-2)][j-1][k][max((int)0,l-2)][1] += dp[i][j][k][l][1]*prob;
                        dp[max((int)0,i-2)][j-1][k][max((int)0,l-2)][1] %= MOD;

                        dp[max((int)0,i-3)][j-1][k][max((int)0,l-3)][1] += dp[i][j][k][l][0]*prob;
                        dp[max((int)0,i-3)][j-1][k][max((int)0,l-3)][1] %= MOD;

                        dp[max((int)0,i-4)][j-1][k][max((int)0,l-4)][1] += dp[i][j][k][l][1]*prob;
                        dp[max((int)0,i-4)][j-1][k][max((int)0,l-4)][1] %= MOD;

                        dp[max((int)0,i-6)][j-1][k][max((int)0,l-6)][1] += dp[i][j][k][l][1]*prob;
                        dp[max((int)0,i-6)][j-1][k][max((int)0,l-6)][1] %= MOD;
                    }

                    else{

                        dp[i-1][j-1][k][max((int)0,l-1)][0] = dp[i][j][k][l][0]*prob;
                        dp[i-1][j-1][k][max((int)0,l-1)][0] %= MOD;

                        dp[max((int)0,i-2)][j-1][k][max((int)0,l-2)][0] += dp[i][j][k][l][1]*prob;
                        dp[max((int)0,i-2)][j-1][k][max((int)0,l-2)][0] %= MOD;

                        dp[max((int)0,i-3)][j-1][k][max((int)0,l-3)][0] += dp[i][j][k][l][0]*prob;
                        dp[max((int)0,i-3)][j-1][k][max((int)0,l-3)][0] %= MOD;

                        dp[max((int)0,i-4)][j-1][k][max((int)0,l-4)][0] += dp[i][j][k][l][1]*prob;
                        dp[max((int)0,i-4)][j-1][k][max((int)0,l-4)][0] %= MOD;

                        dp[max((int)0,i-6)][j-1][k][max((int)0,l-6)][0] += dp[i][j][k][l][1]*prob;
                        dp[max((int)0,i-6)][j-1][k][max((int)0,l-6)][0] %= MOD;

                        dp[max((int)0,i)][j-1][k-1][max((int)0,l)][0] = dp[i][j][k][l][1]*prob;
                        dp[max((int)0,i)][j-1][k-1][max((int)0,l)][0] %= MOD;

                        dp[i-1][j-1][k][max((int)0,l-1)][1] = dp[i][j][k][l][1]*prob;
                        dp[i-1][j-1][k][max((int)0,l-1)][1] %= MOD;

                        dp[max((int)0,i-2)][j-1][k][max((int)0,l-2)][1] += dp[i][j][k][l][0]*prob;
                        dp[max((int)0,i-2)][j-1][k][max((int)0,l-2)][1] %= MOD;

                        dp[max((int)0,i-3)][j-1][k][max((int)0,l-3)][1] += dp[i][j][k][l][1]*prob;
                        dp[max((int)0,i-3)][j-1][k][max((int)0,l-3)][1] %= MOD;

                        dp[max((int)0,i-4)][j-1][k][max((int)0,l-4)][1] += dp[i][j][k][l][0]*prob;
                        dp[max((int)0,i-4)][j-1][k][max((int)0,l-4)][1] %= MOD;

                        dp[max((int)0,i-6)][j-1][k][max((int)0,l-6)][1] += dp[i][j][k][l][0]*prob;
                        dp[max((int)0,i-6)][j-1][k][max((int)0,l-6)][1] %= MOD;
                    }

                }
            }
        }
   }
   int ans = 0;
   for(int i = b; i>=0; i--){
        for(int j=w; j<10; j++){
            ans += (dp[0][i][j][0][0] + dp[0][i][j][0][1])%MOD;
            ans %= MOD;
        }
   }
   cout<<ans<<endl;
   
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}