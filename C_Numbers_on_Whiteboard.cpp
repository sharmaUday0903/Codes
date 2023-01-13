// author : Uday Sharma
// 2022-12-16 19:18:11
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

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    set<int> s;
    REP(i, 1, n + 1)
    {
        s.insert(i);
    }
    cout << 2 << endl;
    int w=n;
    REP(i, 0, n - 1)
    {
        auto p = *s.rbegin();
        int pp = p;
        s.erase(pp);

        auto q = *s.rbegin();
        int qq=q;
        s.erase(qq);
        cout<<pp<<" "<<qq<<endl;
        s.insert(w);
        w--;


    }
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