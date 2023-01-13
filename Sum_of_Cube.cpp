#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);
#define print(a) for(auto x:a) {cout << x << " ";} cout << endl;
#define cnt(x) __builtin_popcountll(x)

using namespace std;

const int mod = 998244353;

signed main()
{
    fastio()

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> v[i];

        vector<int> p(n + 1, 0);
        for (int i = 1; i <= n; i++) p[i] = (p[i - 1] + v[i]) % mod;

        vector<int> g(n + 1, 0);
        for (int i = 1; i <= n; i++) g[i] = (g[i - 1] + p[i]) % mod;

        int f = 0;
        for (int i = 1; i <= n; i++)
        {
            int k1 = (((((p[i] * p[i]) % mod) * p[i]) % mod) * i) % mod;
            f = (f + k1) % mod;

            int k2 = (((((p[i - 1] * p[i - 1]) % mod) * p[i - 1]) % mod) * (n - i + 1)) % mod;
            f = (f - k2 + mod) % mod;

            int k3 = (3 * ((((p[i] * p[i]) % mod) * g[i - 1]) % mod)) % mod;
            f = (f - k3 + mod) % mod;

            int k4 = (3 * ((((p[i - 1] * p[i - 1]) % mod) * ((g[n] - g[i - 1] + mod) % mod)) % mod)) % mod;
            f = (f + k4) % mod;
        }

        cout << f << endl;
    }

    return 0;
}