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
        if (n % 2 == 0)
        {
            
            REPREV(i,1,n+1-2)
            {
                cout<<i<<" ";
            }
            cout<<n-1<<" "<<n<<endl;
        }
        else
        {
           REP(i,1,4)
           {
                cout<<i<<" ";
           }
           REPREV(i,4,n-2+1)
           {
            cout<<i<<" ";
           }
            cout<<n-1<<" "<<n<<endl;


        }
        
    }
}