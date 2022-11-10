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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vi dp(26, 0);
        REP(i, 0, n)
        {
            int c = s[i] - 97;
            dp[c]++;
        }
        // for(auto c:dp)
        // {
        //     cout<<c<<" ";
        // }
        // cout<<endl;
        string ans = "";
        int p = n / k;
        REP(i, 0, k)
        {
            REP(j, 0, 26)
            {
                if (dp[j] == 0)
                {
                    char c = j + 97;
                    ans += c;
                    break;
                }
                else if (p == j)
                {
                    dp[j]--;
                    char c = j + 97;
                    ans += c;
                    break;
                }

                else
                {
                    dp[j]--;
                }
            }
        }
        cout << ans << endl;
    }
}