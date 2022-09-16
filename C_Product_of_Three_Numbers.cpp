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
    REP(u, 0, t)
    {

        int n;
        cin >> n;
        // cout<<"ud\n";
        vi v(2);
        int cnt = 0;
        REP(j, 2, n+ 1)
        {
            if (n % j == 0)
            {
                n /= j;
                v[cnt] = j;
                cnt++;
                if (cnt == 2)
                {
                    break;
                }
            }
        }
        if (n != v[0] && n != v[1] && v[0] != v[1] && v[0] != 0 && v[1] != 0)
        {
            v.pb(n);
        }
        if (v.size() == 3)
        {
            cout << "YES\n";
            for (auto c : v)
            {
                cout << c << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }
}