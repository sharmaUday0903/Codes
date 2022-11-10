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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int p = count(s.begin(), s.end(), '0');
        int q = count(s.begin(), s.end(), '1');
        if(n==1)
        {
            cout<<"YES\n";
        }
        else if (n==2)
        {
            if (p==n||q==n)
            {
                cout<<"YES\n";
                /* code */
            }
            else cout<<"NO\n";
            
        }
        else if (n%2!=0)
        {
            if (abs(p-q)%2==1)
            {
                cout<<"YES\n";
            }
            else cout<<"NO\n";
            
        }
        else
        {
            if (p%2==0&&q%2==0)
            {
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
        
        
        
    }
}