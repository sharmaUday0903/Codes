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
        vi v;
        int plus = 0, minus = 0, num = 0;
        REP(i, 0, n)
        {
            if (s[i] == '+')
            {
                plus++;
                /* code */
            }
            else if (s[i] == '-')
            {
                minus++;
                /* code */
            }
            else
            {
                num++;
                int p = s[i] - 48;
                v.pb(p);
            }
        }
        sortrev(v);
        vector<char> ans;
        while (plus != 0 || minus != 0)
        {
            if (minus != 0)
            {
                char c = v.back() + 48;
                ans.push_back(c);
                ans.pb('-');
                v.pop_back();
                minus--;
            }
            else
            {
                char c = v.back() + 48;
                ans.push_back(c);
                ans.pb('+');
                v.pop_back();
                plus--;
            }
        }

        REPREV(i, 0, v.size())
        {
            char c = v[i] + 48;

            ans.pb(c);
        }
        reverse(ans.begin(), ans.end());
        for (auto c : ans)
        {
            cout << c;
        }
        cout << endl;
    }
}