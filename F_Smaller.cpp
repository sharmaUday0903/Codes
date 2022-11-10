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
        int q;
        cin >> q;
        int cnt1 = 0;
        int cnt2 = 0;
        bool u1 = false;
        bool u2 = false;
        REP(i, 0, q)
        {
            int n, k;
            cin >> n >> k;
            string s;
            cin >> s;
            for (auto c : s)
            {
                if (c == 'a')
                {
                    if (n == 1)
                    {
                        cnt1+=k;
                        /* code */
                    }
                    else
                    {
                        cnt2+=k;
                    }
                }
                else
                {
                    if (n == 1)
                    {
                        u1 = true;
                        /* code */
                    }
                    else
                    {
                        u2 = true;
                    }
                }
            }
            if (u2)
            {
                cout << "YES\n";
                /* code */
            }
            else if (u1)
            {
                cout << "NO\n";

                /* code */
            }

            else
            {
                cout<<(cnt1<cnt2?"YES":"NO")<<endl;
            }
        }
    }
}