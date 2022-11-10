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
        map<int, int> freq;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        vi smaller(n + 4), bigger(n + 4);
        REP(i, 1, n + 1)
        {
            smaller[i] = smaller[i - 1] + freq[i - 1];
        }
        REPREV(i, 0, n + 1)
        {
            bigger[i] = bigger[i + 1] + freq[i + 1];
        }
        int ans = n - 1;
        int xx, yy;
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            bool poss = false;
            REP(x, 1, n + 1)
            {
                int y = x + mid;
                if (y > n)
                {
                    break;
                }
                int ex = smaller[x] + bigger[y];
                int inRange = n - ex;
                if (inRange - ex >= k)
                {
                    poss = true;
                    xx = x;
                    yy = y;
                    break;
                }
            }
            if (poss)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        vi idx;
        idx.pb(-1);
        int prefSum = 0;
        int target = 1;
        for (int i = 0; i < n && target < k; i++)
        {
            if (a[i] >= xx && a[i] <= yy)
            {
                prefSum++;
            }
            else
            {
                prefSum--;
            }
            if (prefSum == target)
            {
                idx.pb(i);
                target++;
            }
        }
        idx.pb(n-1);
        cout<<xx<<" "<<yy<<endl;
        REP(i,1,idx.size())
        {
            cout<<idx[i-1]+2<<" "<<idx[i]+1<<endl;
        }
    }
}