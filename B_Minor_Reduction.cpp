// author : Uday Sharma
// 2022-10-27 21:16:57
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
        string s;
        cin >> s;
        int n = s.length();
        int ans = -1;
        REPREV(i, 0, n - 1)
        {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            int p = a + b;
            if (p >= 10)
            {
                ans = i;
                break;
            }
        }
        if (ans == -1)
        {
            int a = s[0] - '0';
            int b = s[1] - '0';
            int p = a + b;
            cout << p;
            REP(i, 2, n)
            {
                cout << s[i];
            }
            cout << endl;
        }
        else
        {
            REP(i, 0, n)
            {
                if (i == ans)
                {
                    int a = s[i] - '0';
                    int b = s[i + 1] - '0';
                    int p = a + b;
                    cout<<p;
                    i++;
                }
                else
                {
                    cout<<s[i];
                }
                
            }
            cout<<endl;
        }
    }
}