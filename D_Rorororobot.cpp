// author : Uday Sharma
// 2022-10-28 16:03:42
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

template <class T,
          class Cmp = std::less<T>>
struct RMQ
{
    const int n;
    const Cmp cmp;
    std::vector<std::vector<T>> a;
    RMQ(const std::vector<T> &init) : n(init.size()), cmp(Cmp())
    {
        int lg = std::__lg(n);
        a.assign(n, std::vector<T>(lg + 1));
        for (int j = 0; j <= lg; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                a[i][j] = (j == 0 ? init[i] : std::min(a[i][j - 1], a[i + (1 << (j - 1))][j - 1], cmp));
            }
        }
    }
    T rangeMin(int l, int r)
    {
        int k = std::__lg(r - l);
        return std::min(a[l][k], a[r - (1 << k)][k], cmp);
    }
};

signed main()
{
    fast;
    int n, m;
    cin >> n >> m;
    vi a(m);
    REP(i, 0, m)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    RMQ<int, greater<>> rmq(a);
    while (q--)
    {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        ys--;
        yf--;
        if (ys > yf)
        {
            swap(xs, xf);
            swap(ys, yf);
        }
        if ((xs - xf) % k != 0 || (ys - yf) % k != 0)
        {
            cout << "NO\n";
        }
        else
        {
            int lim = xs + (n - xs) / k * k;
            if (rmq.rangeMin(ys, yf + 1) < lim)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
}