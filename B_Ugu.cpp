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
        int ans = 0;
        int cnt1 = count(s.begin(), s.end(), '1');
        int cnt0 = count(s.begin(), s.end(), '0');
        REP(i, 0, n)
        {
            if (cnt1 == n - i)
            {
                break;
            }
            if (s[i] == '1')
            {
                cnt1--;
                int p = cnt1;
                cnt1 = cnt0;
                cnt0 = p;
                ans++;
            }
            else
            {
                cnt0--;
            }

        }
        cout<<ans<<endl;
          
    }
}