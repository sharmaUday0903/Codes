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
        if (n % 2 == 0)
        {
            int p = n / 2;
            int q = n;
            REP(i, 0, n)
            {
                if (i % 2 == 0)
                {
                    cout << p << " ";
                    p--;
                }
                else
                {
                    cout << q << " ";
                    q--;
                }
            }
            cout << endl;
        }
        else
        {
            int p = (n - 1) / 2;
            int q = n - 1;
            REP(i, 0, n - 1)
            {
                if (i % 2 == 0)
                {
                    cout << p << " ";
                    p--;
                }
                else
                {
                    cout << q << " ";
                    q--;
                }
            }
            cout<<n<<" ";
            cout << endl;
        }
    }
}