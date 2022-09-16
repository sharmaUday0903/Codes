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

const int max_n = 2e5 + 101;

int a[max_n], b[max_n], n;
bool good(int x)
{
    int cnt = 0;
    REP(i, 0, n)
    {
        if (x - 1 - a[i] <= cnt && cnt <= b[i])
        {
            cnt++;
        }
    }
    return cnt >= x;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        cin >> n;
        REP(i, 0, n)
        {
            cin >> a[i] >> b[i];
        }
        int l = -1;
        int r = n + 1;
        int mid;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (good(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << l << endl;
    }
}