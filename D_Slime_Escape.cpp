// author : Uday Sharma
// 2022-10-31 11:33:36
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
#define inf 1000000000000000005
#define int long long int

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, k;
        cin >> n >> k;
        vi a(n + 1);
        REP(i, 1, n + 1)
        {
            cin >> a[i];
        }
        if (k == 1 || k == n)
        {
            cout << "YES\n";
            continue;
        }
        int l, r, score;
        l = r = k;
        score = a[k];
        bool u = false;
        while (true)
        {
            int l1, r1;
            l1 = l;
            r1 = r;
            int sum = 0;
            int mn = inf;
            while (l - 1 > 0)
            {
                sum += a[l - 1];
                mn = min(mn, sum);
                l--;
                if (sum >= 0)
                {
                    break;
                }
            }
            if (score + mn >= 0)
            {
                score += sum;
                if (l == 1)
                {
                    u = true;
                    break;
                }
                continue;
            }
            l = l1;
            sum = 0;
            mn = inf;
            while (r + 1 <= n)
            {
                sum += a[r + 1];
                mn = min(mn, sum);
                r++;
                if (sum >= 0)
                {
                    break;
                }
            }
            if (score + mn >= 0)
            {
                score += sum;
                if (r == n)
                {
                    u = true;
                    break;
                }
                continue;
            }
            else
                break;
        }
        u ? cout << "YES\n" : cout << "NO\n";
    }
}