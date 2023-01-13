// author : Uday Sharma
// 2022-12-16 18:49:35
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
    string a;
    cin >> a;
    int ans = 0;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    queue<int> q;
    int cnt = 0;
    REP(i, 0, n)
    {
        if (i > 0 && a[i] != a[i - 1])
        {
            cnt++;
        }
        if (i>0&&a[i]==a[i-1])
        {
            q.push(cnt);
        }
    }
    int del=0;
    REP(i,0,n)
    {
        if (q.empty())
        {
            break;
        }
        q.pop();
        del++;
        ans++;
        while (!q.empty()&&q.front()==i)
        {
            q.pop();
            del++;
        }
        del++;
    }
    ans+=(n-del+1)/2;
    
        
        
        
    cout << ans << endl;
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