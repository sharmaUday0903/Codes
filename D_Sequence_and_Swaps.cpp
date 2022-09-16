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

bool check(vi &v)
{
    REP(i, 1, v.size())
    {
        if (v[i] < v[i - 1])
        {
            return false;
        }
    }
    return true;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, x;
        cin >> n >> x;
        vi a(n);
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        if (check(a))
        {
            cout << 0 << endl;
        }
        else
        {
            int cnt = 0;
            int ans;
            bool uu=true;
            REP(i, 0, n)
            {
                if (a[i] > x)
                {
                    swap(a[i], x);
                    cnt++;
                    if (check(a))
                    {
                        ans = cnt;
                        uu = false;
                        break;
                    }
                }
            }
            if (uu)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<ans<<endl;
            }
            
            
        }
    }
}