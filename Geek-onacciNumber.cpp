// author : Uday Sharma
// 2022-11-01 22:05:25
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

int geek(int n, int a, int b, int c)
{
    if (n == 1)
    {
        return a;
    }
    else if (n == 2)
    {
        return b;
    }
    else if (n == 3)
    {
        return c;
    }
    else
    {
        return geek(n - 1, a, b, c) + geek(n - 2, a, b, c) + geek(n - 3, a, b, c);
    }


}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int ans = geek(n, a, b, c);
        cout << ans << endl;
    }
}