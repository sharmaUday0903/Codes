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
    int n;
    cin >> n;
    vector<string> a(n);
    map<int, int> mask_cnt;
    int ans = 0;
    REP(i, 0, n)
    {
        string s;
        cin >> s;
        vi cnt(26, 0);
        int mask = 0;
        REP(j, 0, s.size())
        {
            cnt[s[j] - 'a']++;
        }
        REP(j, 0, 26)
        {
            if (cnt[j] & 1)
            {
                mask += (1 << j);
            }
        }
        ans += mask_cnt[mask];
        REP(j, 0, 26)
        {
            ans += mask_cnt[mask ^ (1 << j)];
        }
        mask_cnt[mask]++;
    }
    cout<<ans<<endl;
}