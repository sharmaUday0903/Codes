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
        string s;
        cin >> s;
        vector<bool> check(n + 1, false);
        REP(i, 0, n)
        {
            if (s[i] == '0')
            {
                check[i + 1] = true;
            }
        }
        int ans = 0;
        REP(i, 1, n + 1)
        {
            for (int j = i; j <= n; j += i)
            {
                if (check[j] == true)
                {
                    ans += i;
                    check[j] = false;
                }
                else if (check[j] == false && s[j-1] == '1')
                {
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}