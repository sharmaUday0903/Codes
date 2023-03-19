// author : Uday Sharma
// 2023-02-03 22:19:09
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
#define vvi vector<vi>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    map<char, int> m2;
    int ans = 0;
    int cnt=m.size();;
    REP(i, 0, n - 1)
    {
        m2[s[i]]++;

        m[s[i]]--;
        if(m[s[i]]==0)cnt--;
        int p = m2.size() + cnt;
        ans=max(ans,p);
    }
    cout<<ans<<endl;
}
signed main()
{
    fast;
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}