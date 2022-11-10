// author : Uday Sharma
// 2022-10-30 18:51:46
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


// Returns factorial of n
int fact(int n)
{
    if (n == 0)
        return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
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
        int ans = n*(n-1)*(n-2)/6;
        map<int, int> m1, m2;
        vi a(n), b(n);
        REP(i, 0, n)
        {
            cin >> a[i] >> b[i];
            m1[a[i]]++;
            m2[b[i]]++;
        }
        REP(i, 0, n )
        {
            int p = m1[a[i]] - 1;
            int q = m2[b[i]] - 1;
            int ans1=p*q;
            ans-=ans1;
          

        }
        cout<<ans<<endl;
    }
}