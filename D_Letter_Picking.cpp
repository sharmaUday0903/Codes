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
        deque<char> q;
        REP(i, 0, n)
        {
            q.push_back(s[i]);
        }
        bool u = true;
        while (!q.empty())
        {
            int start = q.front();
            int last = q.back();
            if (start == last)
            {
                q.pop_back();
                q.pop_front();
            }
            else
            {
                int start = q.front();
                int last = q.back();
                q.pop_front();
                if (q.back() != start && q.front() != start)
                {
                    u = false;
                    break;
                }
                q.push_front(start);
                q.pop_back();
                if (q.back() != last && q.front() != last)
                {
                    u = false;
                    break;
                }
                q.push_back(last);
                q.pop_back();
                q.pop_back();
            }
        }

        u ? cout << "Draw\n" : cout << "Alice\n";
    }
}