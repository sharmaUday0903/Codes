// author : Uday Sharma
// 2022-11-12 01:45:05
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
    string a = "";
    string b = "";
    map<char, int> m;
    int n = s.length();
    REPREV(i, 0, n)
    {
        if (m[s[i]] == 0)
        {
            b += s[i];
            m[s[i]]++;
        }
    }
    reverse(b.begin(), b.end());
    bool u = true;
    int cnt = 0;
    REP(i, 0, b.size())
    {
        int p = count(s.begin(), s.end(), b[i]);
        if ((p % (i + 1)) != 0)
        {
            u = false;
            break;
        }
        else
        {
            cnt += (p / (i + 1));
        }
    }
    if (!u)
    {
        cout << -1 << endl;
    }
    else
    {
        REP(i, 0, cnt)
        {
            a += s[i];
        }
        string tt = "";
        set<char> ss;
        string bb=b;
        reverse(b.begin(), b.end());
        while (b.size() != 0)
        {
            REP(i, 0, a.size())
            {
                if (ss.find(a[i]) != ss.end())
                {
                }
                else
                {
                    tt += a[i];
                }
            }
            ss.insert(b.back());
            b.pop_back();
        }
        if (tt!=s)
        {
            cout<<-1<<endl;
            /* code */
        }
        else
        {
            cout<<a<<" "<<bb<<endl;
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