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

bool isPalindrome(vector<int> v, int n)
{
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (v[l] != v[r])
        {
            return false;
        }

        l++;
        r--;
    }
    return true;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << "YES\n";
        }
        else
        {
            int l = 0;
            int r = n - 1;
            int p, q;
            while (l < r)
            {
                if (a[l] != a[r])
                {
                    p = a[l];
                    q = a[r];
                    break;
                }

                l++;
                r--;
            }
            vi v1, v2;
            REP(i, 0, n)
            {
                if (a[i] != p)
                {
                    v1.pb(a[i]);
                }
            }
            REP(i, 0, n)
            {
                if (a[i] != q)
                {
                    v2.pb(a[i]);
                }
            }
            if (isPalindrome(v1, v1.size()) || isPalindrome(v2, v2.size()))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}