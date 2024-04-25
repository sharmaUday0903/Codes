// 2024-03-18 19:26:50
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


template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
}
 
template <typename T>
vector<int> manacher(const T &s) {
  return manacher((int) s.size(), s);
}
 

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vvi dp(26, vector<int>(n + 1, 0));
    for (int i = 0; i < 26; i++)
    {
        char ch = i + 'a';
        REP(j, 0, n)
        {
            if (s[j] == ch)
            {
                dp[i][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i][j + 1] = dp[i][j];
            }
        }
    }
    vi pref(n, 0);
    REP(i, 1, n)
    {
        if (s[i] == s[i - 1])
            pref[i] = 1;
    }
     auto pal = manacher(s);
    REP(i, 1, n)
    pref[i] += pref[i - 1];

    REP(i, 0, q)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if ((dp[i][r] - dp[i][l - 1]) != 0)
            {
                cnt++;
            }
        }
        if (cnt == 1 || len == 1)
        {
            cout << 0 << endl;
        }
        else if (cnt > 2)
        {
            
            int ans = (len * (len + 1)) / 2;
            ans--;
            if (pal[l+r-2]>=len/2)
            {
                ans -= len;
            }
            cout << ans << endl;
        }
        else
        {
            if (len % 2 == 0)
            {
                int p = pref[r - 1] - pref[l - 1];
                if (p == 0)
                {
                    int ans = (len * (len + 1)) / 2;
                    ans -= (((len + 1) / 2) * ((len + 1) / 2));
                    cout << ans << endl;
                }
                else
                {
                    int ans = (len * (len + 1)) / 2;
                    ans--;
                    if (pal[l+r-2]>=len/2)
                    {
                        ans -= len;
                    }
                    cout << ans << endl;
                }
            }
            else
            {
                int p = pref[r - 1] - pref[l - 1];
                if (p == 0)
                {
                    int ans = (len * (len + 1)) / 2;
                    ans -= (((len + 1) / 2) * ((len + 1) / 2));
                    cout << ans << endl;
                }
                else
                {
                    int ans = (len * (len + 1)) / 2;
                    ans--;
                    cout << ans << endl;
                }
            }
        }
    }
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;

    while (t--)
        solve();
}