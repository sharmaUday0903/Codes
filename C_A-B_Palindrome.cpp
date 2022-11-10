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
        string s;
        cin >> s;
        bool u = true;
        int n = s.length();
        REP(tt, 0, 2)
        {
            REP(i, 0, n)
            {
                if (s[i] != '?')
                {
                    if (s[n - i - 1] == '?')
                    {
                        s[n - i - 1] = s[i];
                    }
                    if (s[i] != s[n - i - 1])
                    {
                        u = false;
                        break;
                    }
                }
            }
            reverse(s.begin(), s.end());
        }
        if (!u)
        {
            cout << -1 << endl;
        }
        else
        {
            a -= count(s.begin(), s.end(), '0');
            b -= count(s.begin(), s.end(), '1');
            int ques = count(s.begin(), s.end(), '?');
            bool emptyMid = (n % 2 == 1 && s[n / 2] == '?');
            if (a < 0 || b < 0 || a + b != ques || (emptyMid && a % 2 == 0 && b % 2 == 0))
            {
                cout << -1 << endl;
            }
            else
            {
                bool u = true;
                if (a % 2 == 1 || b % 2 == 1)
                {
                    int ii = n / 2;
                    if (s[ii] != '?')
                    {
                        cout << -1 << endl;
                        u = false;
                    }
                    if (u)
                    {
                        s[ii] = (a % 2 == 1 ? '0' : '1');
                        if (a % 2 == 1)
                        {
                            a--;
                        }
                        else
                        {
                            b--;
                        }
                    }
                }
                if (u)
                {
                    if (a % 2 == 1 || b % 2 == 1)
                    {
                        cout << -1 << endl;
                    }
                    else
                    {
                        REP(i, 0, n)
                        {
                            if (s[i] == '?')
                            {
                                int j = s.size() - i - 1;
                                if (a > 0)
                                {
                                    a -= 2;
                                    s[i] = s[j] = '0';
                                }
                                else
                                {
                                    b -= 2;
                                    s[i] = s[j] = '1';
                                }
                            }
                        }
                        cout<<s<<endl;
                    }
                }
            }
        }
    }
}