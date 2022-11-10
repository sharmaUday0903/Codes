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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        deque<string> q;
        int cnt0 = count(s.begin(), s.end(), '0');
        int cnt1 = count(s.begin(), s.end(), '1');
        if (cnt0 == 0)
        {
            string ans(n, '0');
            cout << ans << endl;
        }
        else if (cnt1 == 0)
        {
            string ans(n, '0');
            cout << ans << endl;
        }
        else
        {
            string newS = "";
            REP(i, 0, n)
            {
                if (s[i] == '1')
                {
                    newS += '0';
                }
                else
                {
                    if (i == 0)
                    {
                        if (s[i + 1] == '1')
                        {
                            newS += '1';
                        }
                        else
                        {
                            newS += '0';
                        }
                    }
                    else if (i == n - 1)
                    {
                        if (s[i - 1] == '1')
                        {
                            newS += '1';
                        }
                        else
                        {
                            newS += '0';
                        }
                    }
                    else
                    {
                        if (s[i - 1] == '1' || s[i + 1] == '1')
                        {
                            newS += '1';
                        }
                        else
                        {
                            newS += '0';
                        }
                    }
                }
            }
            // cout << newS << endl;
            int count1 = 0;
            bool u = true;
            REP(i, 0, n)
            {
                if (newS[i] == '1')
                {
                    q.push_back("1");
                    u = true;
                    count1++;
                }
                else
                {
                    if (u)
                    {
                        q.push_back("0");
                        u = false;
                    }
                    else
                    {
                        string x = q.back();
                        q.pop_back();
                        x += '0';
                        q.push_back(x);
                    }
                }
            }
            // for (auto c : q)
            // {
            //     cout << c << endl;
            // }
            k--;
            string ans = "";
            int ee = 0;
            for (auto c : q)
            {
                if (c.length() == 1)
                {
                    if (c == "1")
                    {

                        if (k % 2 == 0)
                        {
                            ans += "1";
                        }
                        else
                        {
                            ans += "0";
                        }
                        ee++;
                    }
                    else
                    {
                        if (k % 2 == 0)
                        {
                            ans += "0";
                        }
                        else
                        {
                            ans += "1";
                        }
                    }
                }
                else
                {
                    if (ee == 0)
                    {
                        int y = c.length() - k - 1;
                        REP(i, 0, c.length())
                        {
                            // if (i < k)
                            // {
                            //     if (i % 2 == k % 2)
                            //     {
                            //         ans += "0";
                            //     }
                            //     else
                            //     {
                            //         ans += "0";
                            //     }
                            // }
                            if (i > y)
                            {
                                if ((c.length() - 1 - i) % 2 == k % 2)
                                {
                                    ans += "0";
                                }
                                else
                                {
                                    ans += "1";
                                }
                            }
                            else
                            {
                                ans += "0";
                            }
                        }
                    }
                    else if (ee == count1)
                    {
                        int y = c.length() - k - 1;
                        REP(i, 0, c.length())
                        {
                            if (i < k)
                            {
                                if (i % 2 == k % 2)
                                {
                                    ans += "0";
                                }
                                else
                                {
                                    ans += "1";
                                }
                            }
                            // else if (i > y)
                            // {
                            //     if ((n - 1 - i) % 2 == k % 2)
                            //     {
                            //         ans += "0";
                            //     }
                            //     else
                            //     {
                            //         ans += "0";
                            //     }
                            // }
                            else
                            {
                                ans += "0";
                            }
                        }
                    }
                    else
                    {
                        int y = c.length() - k - 1;
                        REP(i, 0, c.length())
                        {
                            if (i < k&&c.length()>(2*i))
                            {
                                if (i % 2 == k % 2)
                                {
                                    ans += "0";
                                }
                                else
                                {
                                    ans += "1";
                                }
                            }
                            else if (i > y)
                            {
                                if ((c.length() - 1 - i) % 2 == k % 2)
                                {
                                    ans += "0";
                                }
                                else
                                {
                                    ans += "1";
                                }
                            }
                            else
                            {
                                ans += "0";
                            }
                        }
                    }
                }
            }
            cout << ans << endl;
        }
    }
}