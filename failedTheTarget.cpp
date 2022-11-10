// author : Uday Sharma
// 2022-11-01 21:51:03
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

int recur(int a, int b, int c, int d, int cnt)
{
    if (a < c)
    {
        
        if (cnt < d)
        {
            return recur(a + b, b, c, d, cnt+1);
        }
        else
            return 0;
    }
    else if (a > c)
    {
        if (cnt < d)
        {
            return recur(a - b, b, c, d, cnt+1);
        }
        else
            return 0;
    }
    else
    {
        if ((d - cnt) % 2 == 0)
        {
            return 1;
        }
        else
            return 0;
    }

}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool u = recur(a, b, c, d, 0);
        u ? cout << "yes\n" : cout << "no\n";
    }
}