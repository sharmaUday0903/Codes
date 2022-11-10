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
#define int long long int

const int mod = 998244353;

int printNcR(int n, int r)
{
 
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;
 
    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            // gcd of p, k
            long long m = __gcd(p, k);
 
            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
 
    else
        p = 1;
 
    // if our approach is correct p = ans and k =1
    p%=mod;
    return p;
}

void recurse(int n, vector<vector<int>> &dp)
{
    if (n == 2)
    {
        return;
    }
    recurse(n - 2, dp);

    dp[n][0] = (printNcR(n - 1, n / 2) + dp[n - 2][1]) % mod;
    dp[n][1] = (printNcR(n - 2, n / 2) + dp[n - 2][0]) % mod;
    dp[n][2] = (dp[n - 2][2]) % mod;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        dp[2][0] = 1;
        dp[2][1] = 0;
        dp[2][2] = 1;
        recurse(n, dp);
        cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << endl;
    }
}