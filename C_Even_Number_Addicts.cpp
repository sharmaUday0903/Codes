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
        int cnt0 = 0;
        int cnt1 = 0;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
            {
                cnt0++;
            }
            else
            {
                cnt1++;
            }
        }
        if (cnt1 % 4 == 2)
        {
            cout << "Bob\n";
        }
        else if (cnt1 % 4 == 0)
        {
            cout << "Alice\n";
            /* code */
        }
        else if (cnt1 % 4 == 3)
        {
            cout << "Alice\n";
            /* code */
        }
        else
        {
            if (cnt0 % 2 == 0)
            {
                cout << "Bob\n";
            }
            else
            {
                cout << "Alice\n";
            }
        }
    }
}