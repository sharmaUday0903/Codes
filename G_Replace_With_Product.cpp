// 2023-10-01 16:40:15
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
const int INF = 1e7;
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
    return power(n, mod - 2) % MOD;
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
    int n;
    cin >> n;
    vi a(n);
    REP(i, 0, n)
    cin >> a[i];
    int mul = 1;
    bool u = false;
    for (auto c : a)
    {
        mul *= c;
        if (mul >= INF)
        {
            u = true;
            break;
        }
    }
    if (u)
    {
        int l = 1;
        while (a[l - 1] == 1)
        {
            l++;
        }
        int r = n;
        while (a[r - 1] == 1)
        {
            r--;
        }
        cout << l << " " << r << endl;
    }
    else
    {
        vi prefs(n + 1, 0);
        vi prefm(n + 1, 1);
        REP(i, 1, n + 1)
        {
            prefs[i] = prefs[i - 1] + a[i - 1];
        }
        REP(i, 1, n + 1)
        {
            prefm[i] = prefm[i - 1] * a[i - 1];
        }
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 1)
            {
                temp.pb(i + 1);
            }
        }
        if(temp.empty())
        {
            cout<<1<<" "<<1<<endl;
            return;
        }
        int y = temp.size();
        int l,r;
        int d=INT_MIN;
        REP(i, 0, y)
        {
            REP(j, i , y)
            {
                int sum=prefs[temp[j]]-prefs[temp[i]-1];
                int mul=prefm[temp[j]]/prefm[temp[i]-1];
                int dif=mul-sum;
                if(dif>d)
                {
                    d=dif;
                    l=temp[i];
                    r=temp[j];
                }
            }
        }
        cout<<l<<" "<<r<<endl;
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