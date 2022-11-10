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

const int N = 1e5;

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, k, x;
        cin >> n >> k >> x;
        x--;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        string tt = "";
        int cnt = 0;
        for (auto c : s)
        {
            if (c == 'a')
            {
                tt += string(x % ((cnt * k) + 1), 'b');
                x /= (cnt * k + 1);
                tt += c;
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        tt += string(x % (cnt * k + 1), 'b');
        reverse(tt.begin(), tt.end());
        cout << tt << endl;
    }
}