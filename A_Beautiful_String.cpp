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
        bool u = true;
        REP(i, 0, n - 1)
        {
            if (s[i] == s[i + 1] && s[i] != '?')
            {
                u = false;
                break;
            }
        }
        if (!u)
        {
            cout << -1 << endl;
        }
        else
        {
            string ans = "";
            REP(i, 0, n)
            {
                if (s[i] == '?')
                {
                    set<char> set;
                    set.insert('a');
                    set.insert('b');
                    set.insert('c');
                    if (i != 0)
                    {
                        set.erase(s[i - 1]);
                    }
                    if (i != n - 1)
                    {
                        if (s[i + 1] != '?')
                        {
                            if (set.find(s[i + 1]) != set.end())
                            {
                                set.erase(s[i + 1]);
                            }
                            auto cc = *set.begin();
                            char pp = cc;
                            s[i] = pp;
                        }
                        else
                        {
                            auto cc = *set.begin();
                            char pp = cc;
                            s[i] = pp;
                        }
                    }
                    else
                    {
                        auto cc = *set.begin();
                        char pp = cc;
                        s[i] = pp;
                    }
                }
            }
            cout<<s<<endl;
        }
    }
}