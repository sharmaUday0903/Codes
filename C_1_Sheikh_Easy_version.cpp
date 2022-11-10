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
        int n, q;
        cin >> n >> q;
        int a[n + 1];
        REP(i, 1, n + 1)
        {
            cin >> a[i];
        }
        int l, r;
        cin >> l >> r;
        int prefSum[n + 1];
        prefSum[0] = 0;
        int prefXor[n + 1];
        prefXor[0] = 0;
        REP(i, 1, n + 1)
        {
            prefSum[i] = prefSum[i - 1] + a[i];
        }
        REP(i, 1, n + 1)
        {
            prefXor[i] = prefXor[i - 1] ^ a[i];
        }
        int ans = prefSum[r] - prefSum[l - 1] - (prefXor[r] ^ prefXor[l - 1]);
        int x = l, y = r;
        int j = l;
        int len = n;
        REP(i, l, r + 1)
        {
            j = max(j, i);
            while (j <= r && (prefSum[j] - prefSum[i - 1] - (prefXor[j] ^ prefXor[i - 1])) != ans)
            {
                j++;
            }
            if (j <= r && (prefSum[j] - prefSum[i - 1] - (prefXor[j] ^ prefXor[i - 1])) == ans && (j - i + 1) < len)
            {
                x = i;
                y = j;
                len = j - i + 1;
            }
        }
        cout<<x<<" "<<y<<endl;
    }
}