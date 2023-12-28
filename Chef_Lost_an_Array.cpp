// 2023-11-22 20:57:14
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
    int n, d;
    cin >> n >> d;
    vi b(n), c(n);
    REP(i, 0, n)
    cin >> b[i];
    REP(i, 0, n)
    cin >> c[i];
    vi fb(n, -1);
    vi fc(n, -1);
    fb[0] = b[0];
    fc[0] = c[0];
    REP(i, 1, n)
    {
        if (b[i] != b[i - 1])
        {
            fb[i] = b[i];
        }
        if (c[i] != c[i - 1])
        {
            fc[i] = c[i];
        }
    }
    bool u = true;
    u &= is_sorted(b.begin(), b.end());
    vi cc = c;
    reverse(cc.begin(), cc.end());
    u &= is_sorted(cc.begin(), cc.end());
   
    REP(i, 0, n)
    {
        if (fc[i] != -1 && fb[i] != -1 && fc[i] != fb[i])
        {
            cout << "NO\n";
            return;
        }
        if (!u)
        {
            cout << "NO\n";
            return;
        }
    }
    vi ans(n, -1);
    REP(i, 0, n)
    {
        if (fc[i] != -1)
        {
            ans[i] = fc[i];
        }
        else if (fb[i] != -1)
        {
            ans[i] = fb[i];
        }
       
    }

    int last = 0;
    int lastv = ans[0];

    REP(i, 1, n)
    {
        if (ans[i] != -1)
        {
            int p = i - last;
            if (p == 1)
            {
                lastv=ans[i];
                last=i;
                continue;
            }
            int q = abs(ans[i] - lastv);
            int div = q / p;
            int mod = q % p;
            if (lastv > ans[i])
            {
                for (int j = last + 1; j < i; j++)
                {
                    if (mod)
                    {
                        ans[j] = ans[j - 1] - (div + 1);
                        mod--;
                    }
                    else
                    {

                        ans[j] = ans[j - 1] - (div);
                    }
                }
            }
            else
            {
                for (int j = last + 1; j < i; j++)
                {
                    if (mod)
                    {
                        ans[j] = ans[j - 1] + (div + 1);
                        mod--;
                    }
                    else
                    {

                        ans[j] = ans[j - 1] + (div);
                    }
                }
            }
            last = i;
            lastv = ans[i];
        }
    }

    int ll;
    REP(i, 0, n)
    {
        if (ans[i] != -1)
            ll = ans[i];
    }

    REPREV(i, 0, n)
    {
        if (ans[i] == -1)
        {
            ans[i] == ll;
        }
        else
            break;
    }

    REP(i,1,n)
    {
        if(ans[i]==-1)
        ans[i]=ans[i-1];
    }
    REP(i, 1, n)
    {
        if (abs(ans[i] - ans[i - 1]) > d)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (auto c : ans)
        cout << c << " ";
    cout << endl;
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}