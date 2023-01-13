// author : Uday Sharma
// 2022-12-13 21:28:47
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

void solve()
{
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    if (n == 1)
    {
        if (a == b)
        {
            cout << 1 << endl;
            cout << a << ":" << a << endl;
        }
        else
        {
            cout << 0 << endl;
            cout << a << ":" << b << endl;
        }
        return;
    }
    if (a + b < n)
    {
        cout << n - a - b << endl;
        vpi v(n, {0, 0});
        REP(i, 0, a + b)
        {
            v[i].first = 1;
        }
        REP(i, 0, b)
        {
            swap(v[i].f, v[i].s);
        }
        for (auto c : v)
        {
            cout << c.f << ":" << c.s << endl;
        }
    }
    else
    {
        cout << 0 << endl;
        vpi v(n, {0, 0});
        int sum = a + b;
        REP(i, 0, n - 1)
        {
            v[i].f = 1;
        }
        sum = sum - n + 1;
        v[n - 1].f = sum;
        int rem = b;
        REP(i, 0, n - 1)
        {
            swap(v[i].f, v[i].s);
            rem--;
            if (rem == 0)
            {
                break;
            }
        }
        if (rem)
        {
            v[n-1].f-=rem;
            v[n-1].s+=rem;
        }
        if (v[n-1].f==v[n-1].s)
        {
            v[0].s+=v[n-1].s;
            v[n-1].s=0;
        }
        
       
        
        

        for (auto c : v)
        {
            cout << c.f << ":" << c.s << endl;
        }
    }
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}