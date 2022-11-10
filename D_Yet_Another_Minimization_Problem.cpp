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
        int a[n], b[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        REP(i, 0, n)
        {
            cin >> b[i];
        }
        int w = 0;
        REP(i, 0, n)
        {
            w += (a[i] * a[i]);
            w += (b[i] * b[i]);
        }
        w *= n - 2;
        int sum = 0;
        REP(i, 0, n)
        {
            sum += a[i];
            sum += b[i];
        }
        vector<bool> check(sum + 1);
        check[0] = true;
        REP(i, 0, n)
        {
            REPREV(j, 0, sum + 1)
            {
                if (check[j])
                {
                    if (j + a[i] <= sum)
                    {
                        check[j + a[i]] = true;
                    }
                    if (j + b[i] <= sum)
                    {
                        check[j + b[i]] = true;
                    }
                    check[j] = false;
                }
            }
        }
        int best = -1;
        REP(i, 0, sum + 1)
        {
            if (check[i])
            {
                if (abs(2 * i - sum) < abs(2 * best - sum))
                {
                    best = i;
                }
            }
        }
        int ans=best*best+(sum-best)*(sum-best);
        ans+=w;
        cout<<ans<<endl;
    }
}