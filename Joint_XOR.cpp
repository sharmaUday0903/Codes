// author : Uday Sharma
// 2022-10-27 17:00:16
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
        if (p == 0 || q == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            int firstZero = -1;
            int firstOne = -1;
            REP(i, 0, n)
            {
                if (s[i] == '1')
                {
                    firstOne = i;
                    break;
                }
            }
            REP(i, 0, n)
            {
                if (s[i] == '0')
                {
                    firstZero = i;
                    break;
                }
            }
            if (firstZero > firstOne)
            {
                int len = n - firstZero;
                int cnt = 0;
                while (firstZero <= n - 1 && s[firstZero] == '0')
                {
                    firstZero++;
                    cnt++;
                }
            }
            else
            {
            }
        }
    }
}