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
        string a, b;
        cin >> a >> b;
        int n = a.size();
        int m = b.size();

        if (a[n - 1] == b[m - 1])
        {
            if (n > m && a[n - 1] == 'S')
            {
                cout << "<" << endl;
            }
            else if (n < m && a[n - 1] == 'L')
            {
                cout << "<" << endl;
            }
            else if (n == m)
            {
                cout << "=" << endl;
            }
            else
            {
                cout << ">" << endl;
            }
        }

        else if (a[n - 1] == 'L')
        {
            cout << ">" << endl;
        }
        else if (b[m - 1] == 'L')
        {
            cout << "<" << endl;
        }

        else if (a[n - 1] == 'S')
        {
            cout << "<" << endl;
        }
        else if (b[m - 1] == 'S')
        {
            cout << ">" << endl;
        }
    }
}