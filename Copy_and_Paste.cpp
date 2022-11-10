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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int p = count(s.begin(), s.end(), '1');
        if (p == 0)
        {
            int ans = n*m;
            cout << ans << endl;
        }
        else
        {
            if (m % 2 == 0)
            {
                int ans = 1;
                int l = 0;
                while (s[l] == '0')
                {
                    ans++;
                    l++;
                }
                l = n - 1;
                while (s[l] == '0')
                {
                    ans++;
                    l--;
                }
                cout << ans << endl;
            }
            else
            {
                if (p % 2 != 0)
                {
                    cout << 0 << endl;
                }
                else
                {
                    int cnt = 0;
                    int pp = -1;
                    REP(i, 0, n)
                    {
                        if (s[i] == '1')
                        {
                            cnt++;
                            if (cnt == (p / 2))
                            {
                                pp = i;
                                break;
                            }
                        }
                    }
                    int ans = 1;
                    int l = pp + 1;
                    while (s[l] == '0')
                    {
                        ans++;
                        l++;
                    }
                    cout<<ans<<endl;
                }
            }
        }
    }
}