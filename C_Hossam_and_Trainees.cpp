// author : Uday Sharma
// 2022-12-13 01:11:28
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

const int N = 32000;
vi spf;
vector<bool> isPrime(N + 1, true);
void sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i] == true)
        {
            spf.pb(i);
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    REP(i, 0, n)
    cin >> a[i];
    for (auto c : spf)
    {
        int cnt = 0;
        REP(i, 0, n)
        {
            if (a[i] % i == 0)
            {
                cnt++;
            }
        }
        if (cnt > 1)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
signed main()
{
    fast;
    sieve();
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}