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

int subarraySum(vector<int> v, int size)
{
    int ans = 0;
    int cnt = 0;
    REP(i, 0, size)
    {
        int a = v[i] + cnt;
        if (a>0)
        {
            cnt = a;
            /* code */
        }
        else
        {
            cnt = 0;
        }

        ans = max(cnt, ans);
    }
    return ans;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, x;
        cin >> n >> x;
        vi v;
        REP(i, 0, n)
        {
            int x;
            cin >> x;
            v.pb(x);
        }
        vi ans(n + 1);
        ans[0] = subarraySum(v, n);
        int e = *max_element(v.begin(), v.end());
        int l, r;
        REP(i, 0, n)
        {
            if (i == 0)
            {
                REP(j, 0, n)
                {
                    if (v[j] == e)
                    {
                        l = j;
                        r = j;
                        break;
                    }
                }
                v[l] += x;
                ans[i + 1] = subarraySum(v, n);
            }
            else
            {
                if (l == 0)
                {
                    r++;
                    v[r] += x;
                    ans[i + 1] = subarraySum(v, n);
                }
                else if (r == n - 1)
                {
                    l--;
                    v[l] += x;
                    ans[i + 1] = subarraySum(v, n);
                }
                else
                {
                    if (v[l - 1] >= v[r + 1])
                    {
                        l--;
                        v[l] += x;
                        ans[i + 1] = subarraySum(v, n);
                    }
                    else
                    {
                        r++;
                        v[r] += x;
                        ans[i + 1] = subarraySum(v, n);
                    }
                }
            }
        }
        for (auto c : ans)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}