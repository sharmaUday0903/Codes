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

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vpi afactors, bfactors;

        for (int i = 1; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                afactors.pb({i, a / i});
                afactors.pb({a / i, i});
            }
        }
        for (int i = 1; i * i <= b; i++)
        {
            if (b % i == 0)
            {
                bfactors.pb({i, b / i});
                bfactors.pb({b / i, i});
            }
        }
        bool u=false;
        for (auto adiv : afactors)
        {
            for (auto bdiv : bfactors)
            {
                int a1 = adiv.f, a2 = adiv.s;
                int b1 = bdiv.f, b2 = bdiv.s;

                int x = a1 * b1;
                int y = a2 * b2;
                int k1 = a / x + 1;
                int k2 = b / y + 1;
                if (k1 * x <= c && k2 * y <= d)
                {
                    cout << k1 * x << " " << k2 * y << endl;
                    u=true;
                    break;
                }
            }
            if (u)
            {
                break;
            }
            
        }
        if (!u)
        {
            cout<<-1<<" "<<-1<<endl;
            /* code */
        }
        
    }
}