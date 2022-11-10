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
        int n;
        cin >> n;
        int sum = 0;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            sum += a[i];
        }
        int p = (n * (n + 1)) / 2;
        if (sum % p != 0)
        {
            cout << "NO\n";
        }
        else
        {
            bool u = true;
            vi ans;
            int y = sum / p;
            REP(i, 0, n)
            {
                if (i == 0)
                {
                    int q = (y - (a[0] - a[n - 1])) ;
                    if (q%n==0&&q/n>=1)
                    {
                        ans.pb(q/n);
                    }
                    else
                    {
                        u = false;
                    }
                }
                else
                {
                    int q = (y - (a[i] - a[i - 1])) ;
                    if (q%n==0&&q/n>=1)
                    {
                        ans.pb(q/n);
                    }
                    else
                    {
                        u = false;
                    }
                }
            }
            if (u)
            {
                cout << "YES\n";
                for (auto c : ans)
                {
                    cout << c << " ";
                }
                cout << endl;
                /* code */
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}