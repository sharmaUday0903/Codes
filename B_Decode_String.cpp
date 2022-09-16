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
        string a;
        cin >> a;
        string ans = "";
        REPREV(i, 0, n)
        {
            if (a[i] == '0')
            {
                int p = a[i - 1] - 48;
                int q = a[i - 2] - 48;
                int qq = (q * 10) + p;
                char c = qq + 96;
                ans += c;
                i -= 2;
            }
            else
            {
                int p = a[i]-48;
                char c = p + 96;
                ans += c;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}