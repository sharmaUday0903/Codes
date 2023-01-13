// author : Uday Sharma
// 2022-12-16 00:07:24
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

long double v;

long double solve(long double c, long double m)
{
    long double p = 1 - c - m;
    long double ans = 0;
    ans += p;
    if (c > 0.000001)
    {
        if (c - v > 0.000001)
        {
            if (m > 0.000001)
            {
                ans += c * (1 + solve(c - v, m + v / 2));
            }
            else
            {
                ans += c * (1 + solve(c - v, 0));
            }
        }
        else
        {
            if (m > 0.000001)
            {
                ans += c * (1 + solve(0, m + c / 2));
            }
            else
            {
                ans += c * (1 + solve(0, 0));
            }
        }
    }
    if (m>0.000001)
    {
        if (m-v>0.000001)
        {
            if (c>0.000001)
            {
                ans+=m*(1+solve(c+v/2,m-v));
            }
            else
            {
                ans+=m*(1+solve(0,m-v));
            }
        }
        else
        {
            if (c > 0.000001)
            {
                ans += m * (1 + solve(c + m / 2, 0));
            }
            else
            {
                ans += m * (1 + solve(0, 0));
            }
        }
        
            
            
        
    }
    return ans;
    
}
signed main()
{
    fast;
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        long double c, m, p;
        cout << fixed << setprecision(10);
        cin >> c >> m >> p >> v;
        cout << solve(c, m) << endl;
    }
}