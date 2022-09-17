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
bool isPalindrome(string s)
{
    for (int i = 0; i < (s.length()) / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}
vector<vector<int>> palindromePairs(vector<string> &words)
{
    int n = words.size();
    vi v;
    vector<vector<int>> ans;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        m[words[i]] = i + 1;
    }

    if (m[""] != 0)
    {
        int idx = m[""] - 1;
        for (int i = 0; i < n; i++)
        {
            if (i != idx && isPalindrome(words[i]))
            {
                vector<int> vv;
                vv.push_back(i);
                vv.push_back(idx);
                ans.push_back(vv);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        string a = words[i];
        reverse(a.begin(), a.end());
        if (m[a] != 0 && m[a] != i + 1)
        {
            vector<int> vv;
            vv.push_back(i);
            vv.push_back(m[a] - 1);
            ans.push_back(vv);
        }
    }
    for (int i = 0; i < n; i++)
    {
        string ss = words[i];
        for (int j = 1; j < ss.length(); j++)
        {
            string left = ss.substr(0, j);
            string right = ss.substr(j);
            if (isPalindrome(left))
            {
                string b = right;
                reverse(b.begin(), b.end());
                if (m[b] != 0)
                {
                    vector<int> vv;
                    vv.push_back(i);
                    vv.push_back(m[b] - 1);
                    ans.push_back(vv);
                }
            }
            if (isPalindrome(right))
            {
                string a = left;
                reverse(a.begin(), a.end());
                if (m[a] != 0)
                {
                    vector<int> vv;
                    vv.push_back(i);
                    vv.push_back(m[a] - 1);
                    ans.push_back(vv);
                }
            }
        }
    }
    return ans;
}
signed main()
{
    fast;
    vector<string> v;
    REP(i, 0, 6)
    {
        string s;
        cin >> s;
        v.pb(s);
    }
    vector<vi> ans = palindromePairs(v);
    for (auto c : ans)
    {
        for (auto d : c)
        {
            cout << d << " ";
        }
        cout << endl;
    }
}