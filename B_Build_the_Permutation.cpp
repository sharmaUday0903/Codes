#include <bits/stdc++.h>
// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
// template<typename T>
// using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 998244353 ;//1e9 + 7;

// Macros
#define F first
#define S second
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define int long long

// Custom hash map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}

template <typename T>
int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }

// Mathematical functions
int GCD(int a, int b) {
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int GCD_extended(int a, int b, int &x, int &y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int LCM(int a, int b)
{
    return ((ll)a * b) / GCD(a, b);
}

ll modpow(ll x, ll n, int m = MOD)
{
    if (x == 0 && n == 0) return 0; // undefined case
    ll res = 1;
    while (n > 0) 
    {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int modinv(int x, int m = MOD)
{   
    return modpow(x, m - 2, m);
}

mt19937 rng;
int getRandomNumber(int l, int r)
{
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

// void allocateStackMax()
// {
//     rlimit R;
//     getrlimit(RLIMIT_STACK, &R);
//     R.rlim_cur = R.rlim_max;
//     setrlimit(RLIMIT_STACK, &R);
// }

/**
 * SUBSCRIBE TO MY YT CHANNEL
 * CMC https://www.youtube.com/channel/UCt_wvjXhvarpI64wBrYAYQw
 * SHAMELES PLUG :D
 */

// Flags to use: -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
///////////////////////////////////////////////////////////// START CODE HERE /////////////////////////////////////////////////////////////

void preSolve()
{
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    // allocateStackMax();
}

void solve(int tc)
{
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) > 1 || a + b > n - 2)
        return void(print(-1));
    
    vector<int> ans(n);
    set<int> rem;
    for (int i = 1; i <= n; i++)
        rem.insert(i);

    if (a > b)
    {
        int x = n;
        for (int i = 1, cnt = 0; cnt < a; i += 2, cnt++)
        {
            ans[i] = x;
            rem.erase(x);
            x--;
        }
        x = 1;
        for (int i = 2, cnt = 0; cnt < b; i += 2, cnt++)
        {
            ans[i] = x;
            rem.erase(x);
            x++;
        }
        for (int i = 0; i < n; i++)
        {
            if (!ans[i])
            {
                ans[i] = *rem.rbegin();
                rem.erase(ans[i]);
            }
        }
    } else if (a < b) {
        int x = 1;
        for (int i = 1, cnt = 0; cnt < b; i += 2, cnt++)
        {
            ans[i] = x;
            rem.erase(x);
            x++;
        }
        x = n;
        for (int i = 2, cnt = 0; cnt < a; i += 2, cnt++)
        {
            ans[i] = x;
            rem.erase(x);
            x--;
        }
        for (int i = 0; i < n; i++)
        {
            if (!ans[i])
            {
                ans[i] = *rem.begin();
                rem.erase(rem.begin());
            }
        }
    } else {
        int x = n;
        for (int i = 1, cnt = 0; cnt < a; i += 2, cnt++)
        {
            ans[i] = x;
            rem.erase(x);
            x--;
        }
        x = 1;
        for (int i = 2, cnt = 0; cnt < b; i += 2, cnt++)
        {
            ans[i] = x;
            rem.erase(x);
            x++;
        }
        for (int i = 0; i < n; i++)
        {
            if (!ans[i])
            {
                ans[i] = *rem.begin();
                rem.erase(rem.begin());
            }
        }
    }

    print(ans);
}

int32_t main()  
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;

    preSolve();
    int tests = 1;
    cin >> tests;
    for (int tt = 1; tt <= tests; tt++)
        solve(tt);
    return 0;
}