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

const int N = 100003;
vector<vector<int>> v;
vector<int> ans(N);
vector<int> a(N);

void SieveOfEratosthenes(int N)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[N + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= N; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            v[p].pb(a[p - 1]);
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= N; i += p)
                v[p].push_back(a[i - 1]);
        }
    }

    // Print all prime numbers
    ans[0]=a[0];
    REP(i, 1, N)
    {
        int p =i+1;
    }
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
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int q;
        cin >> q;
        REP(i, 0, q)
        {
            int p, k;
            cin >> p >> k;
        }
    }
}