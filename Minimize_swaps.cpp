// author : Uday Sharma
// 2022-11-13 11:52:52
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

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int cnt1 = count(s.begin(), s.end(), '1');
    if (cnt1 == 0)
    {
        cout << 0 << endl;
    }
    else if (cnt1 == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        int cnto = 0, cnte = 0;
        REP(i, 0, n)
        {
            if (s[i] == '1')
            {
                if (i % 2 == 0)
                {
                    cnto++;
                }
                else
                {
                    cnte++;
                }
            }
        }
        int diff = abs(cnto - cnte);
        if (cnt1 % 2 == 0)
        {
            if (diff % 3 == 0)
            {
                cout << 0 << endl;
            }
            else if (diff % 3 == 2)
            {
                cout << 1 << endl;
            }
            else
            {
                int mn = min(cnto, cnte);
                if (mn == 0)
                {
                    cout << 2 << endl;
                }
                else
                {
                    cout << 1 << endl;
                }
            }
        }
        else
        {
            if (n < cnt1 + 2)
            {
                cout << -1 << endl;
            }

            else
            {
                if (diff % 3 == 0)
                {
                    cout << 0 << endl;
                }
                else if (diff % 3 == 2)
                {
                    cout << 1 << endl;
                }
                else
                {
                    int mn = min(cnto, cnte);
                    if (mn == 0)
                    {
                        cout << 2 << endl;
                    }
                    else
                    {
                        if (diff > 1)
                        {
                            cout << 1 << endl;
                        }
                        else
                        {
                            bool u = false;
                            int cntt = 0;
                            if (cnto > cnte)
                            {
                                REP(i, 0, n)
                                {
                                    if (s[i] == '1')
                                    {
                                        if (i % 2 != 0)
                                        {
                                            if (i > 0 && s[i - 1] == '0')
                                            {
                                                u = true;
                                                break;
                                            }
                                            if (i < n - 1 && s[i + 1] == '0')
                                            {
                                                u = true;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            if (i > 0 && s[i - 1] == '0')
                                            {
                                                cntt++;
                                                continue;
                                            }
                                            if (i < n - 1 && s[i + 1] == '0')
                                            {
                                                cntt++;
                                            }
                                        }
                                    }
                                }
                                if (u)
                                {
                                    cout << 1 << endl;
                                }
                                else
                                {
                                    if (cntt > 1)
                                    {
                                        cout << 2 << endl;
                                    }
                                    else
                                    {
                                        cout << 3 << endl;
                                    }
                                }
                            }
                            else
                            {
                                REP(i, 0, n)
                                {
                                    if (s[i] == '1')
                                    {
                                        if (i % 2 == 0)
                                        {
                                            if (i > 0 && s[i - 1] == '0')
                                            {
                                                u = true;
                                                break;
                                            }
                                            if (i < n - 1 && s[i + 1] == '0')
                                            {
                                                u = true;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            if (i > 0 && s[i - 1] == '0')
                                            {
                                                cntt++;
                                                continue;
                                            }
                                            if (i < n - 1 && s[i + 1] == '0')
                                            {
                                                cntt++;
                                            }
                                        }
                                    }
                                }
                                if (u)
                                {
                                    cout << 1 << endl;
                                }
                                else
                                {
                                    if (cntt > 1)
                                    {
                                        cout << 2 << endl;
                                    }
                                    else
                                    {
                                        cout << 3 << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
signed main()
{
    fast;
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}