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
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int cnt = 0;
        int cnt1 = 0;
        REP(i, 0, n)
        {
            if (i % 2 != a[i] % 2)
            {
                cnt1++;
            }
            else if (i % 2 == a[i] % 2 && i%2==0)
            {
                cnt1+=2;
            }
            else if (i % 2 == a[i] % 2 && i%2!=0&&a[i]!=1)
            {
                cnt1++;
            }
            
        }
        int p = cnt1;
        if (p % 2 == 0)
        {
            cout << "CHEFINA\n";
        }
        else
        {
            cout << "CHEF\n";
        }
    }
}