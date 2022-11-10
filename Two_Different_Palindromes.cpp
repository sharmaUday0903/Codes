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
        int a, b;
        cin >> a >> b;
        if (a < b)
        {
            /* code */
            swap(a, b);
        }

        if (a % 2 == 1 && b % 2 == 1)
        {
            cout << "No\n";
            /* code */
        }
        else if (a%2==0 && b%2==1)
        {
            if (b==1)
            {
                cout<<"No\n";
                /* code */
            }
            else cout<<"Yes\n";
            
        }
        else
        {
            cout<<"Yes\n";
        }
        
    }
}