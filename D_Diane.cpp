// author : Uday Sharma
// 2022-10-31 01:41:14
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
            REP(i, 0, n / 2)
            {
                cout << 'a';
            }
            cout << 'b';
            REP(i, 0, (n / 2) - 1)
            {
                cout << 'a';
            }
        }
        else
        {
            if(n>1){
            REP(i, 0, n / 2)
            {
                cout << 'a';
            }
            cout <<"bc";
            REP(i, 0, (n / 2) - 1)
            {
                cout << 'a';
            }
            }
            else cout<<'a';
        }
        cout<<endl;
        }
}