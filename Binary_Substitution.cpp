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
            cout << n << " " << 0 << endl;
        }
        else
        {
            cout << 1 << " " << abs(p - q) + 1 << endl;
            if (p == q)
            {
                cout << 1 << " " << n << " " << 0 << endl;
            }
            else if (p < q)
            {
                int k = q - p;
                string w = s;
                while (k)
                {
                    string ans = "";
                    bool u = true;
                    REP(i, 0, w.length())
                    {
                        if (i < w.length() - 1 && w[i] != w[i + 1] && u == true)
                        {
                            cout << i + 1 << " " << i + 2 << " " << 0 << endl;
                            ans += '0';
                            i++;
                            u = false;
                        }
                        else
                        {
                            ans += w[i];
                        }
                    }
                    w = ans;

                    k--;
                }
                cout << 1 << " " << w.length() << " 0\n";
            }
            else
            {
                int k = p - q;
                string w = s;
                while (k)
                {
                    string ans = "";
                    bool u = true;
                    REP(i, 0, w.length())
                    {
                        if (i < w.length() - 1 && w[i] != w[i + 1] && u == true)
                        {
                            cout << i + 1 << " " << i + 2 << " " << 1 << endl;
                            ans += '1';
                            i++;
                            u = false;
                        }
                        else
                        {
                            ans += w[i];
                        }
                    }
                    w = ans;

                    k--;
                }
                cout << 1 << " " << w.length() << " 1\n";
            }
        }
    }
}