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
    set<int> s;
        map<int, int> m;
    REP(i, 0, t)
    {
        char c;
        cin >> c;
        int n;
        cin >> n;
        if (c == '+')
        {
            s.insert(n);
            m[n]=n;
        }
       
        
        else
        {
            int p = max(n,m[n]);
            while (true)
            {
                if (s.find(p) == s.end())
                {
                    cout << p << endl;
                    m[n] = p;
                    break;
                }

                p += n;
            }
        }
    }
}




















































