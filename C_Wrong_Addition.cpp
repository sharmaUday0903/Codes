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
        int a, b;
        cin >> a >> b;
        string ans ="";
        bool u = true;
        while (b != 0)
        {
            int p = a % 10;
            int q = b % 10;
            if (p <= q)
            {
                int w = q - p;
                char c = w+48;
                ans +=c;
                a /= 10;
                b /= 10;
            }
            else
            {
                q = b % 100;
                int w = q - p;
                if (w >= 10||w<=0)
                {
                    u = false;
                    break;
                }
                else
                {
                    char c=w+48;
                    ans+=c;
                    a /= 10;
                    b /= 100;
                }
            }
        }
        if (a == 0 &&b == 0 &&u == true)
        {
            while (ans.back()=='0')
            {
                ans.pop_back();
                /* code */

            }
            reverse(ans.begin(),ans.end());
            
            cout << ans << endl;
            /* code */
        }
        else
        {
            cout<<-1<<endl;
        }
        
    }
}