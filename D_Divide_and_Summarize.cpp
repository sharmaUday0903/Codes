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

set<int> s;
void find(vi a)
{
    int p = *max_element(a.begin(), a.end());
    int q = *min_element(a.begin(), a.end());
    int s0 = 0;
    for (auto num : a)
    {
        s0 += num;
    }
    s.insert(s0);
    int pp = (p + q) / 2;
    int s1 = 0, s2 = 0;
    vi v1, v2;
    for (auto num : a)
    {
        if (num <= pp)
        {
            v1.pb(num);
            s1 += num;
        }
        else
        {
            v2.pb(num);
            s2 += num;
        }
    }
    s.insert(s1);
    s.insert(s2);
    if (v1.size() > 0 && v2.size() > 0)
    {
        find(v1);
        find(v2);
    }
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        s.clear();
        int n, q;
        cin >> n >> q;
        int sum = 0;
        vi a(n);
        REP(i, 0, n)
        {
            cin >> a[i];
            sum += a[i];
        }
        sortv(a);
        find(a);
        REP(i,0,q)
        {
            int x;
            cin>>x;
            if (s.find(x)!=s.end())
            {
                cout<<"Yes\n";
            }
            else cout<<"No\n";


            
            
        }
    }
}