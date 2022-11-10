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
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        vector<bool> check(n, false);

        bool ans = false;
        REP(i, 0, n)
        {
            int p = i + a[i] + 1;
            if (i != 0)
            {
                if (check[i - 1] == true)
                {
                    if (p == n)
                    {
                        ans = true;
                        break;
                    }
                    if (p < n)
                    {
                        check[p - 1] = true;
                    }
                }
                  int q = i - a[i];
                    if (q == 0 || (q > 0 && check[q - 1] == true))
                    {
                        check[i] = true;
                    }
                
            }
            else
            {
                if (p < n)
                {
                    check[p - 1] = true;
                }
            }
        }
        if (a[0] == n - 1 || check[n - 1] == true)
        {
            ans = true;
        }
        // for(auto c:check)
        // {
        //     cout<<c<<" ";
        // }
        // cout<<endl;
        ans ? cout << "YES\n" : cout << "NO\n";
    }
}