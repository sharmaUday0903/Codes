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
template <typename T>
struct binary_indexed_tree
{
    int N;
    vector<T> BIT;
    binary_indexed_tree(int N) : N(N), BIT(N + 1, 0)
    {
    }
    void add(int i, T x)
    {
        i++;
        while (i <= N)
        {
            BIT[i] += x;
            i += i & -i;
        }
    }
    T sum(int i)
    {
        T ans = 0;
        while (i > 0)
        {
            ans += BIT[i];
            i -= i & -i;
        }
        return ans;
    }
    T sum(int L, int R)
    {
        return sum(R) - sum(L);
    }
};
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
            a[i]--;
        }
        binary_indexed_tree<int> BIT(n);
        int ans=0;
        REP(j,0,n)
        {
            ans+=BIT.sum(a[j],n);
            BIT.add(a[j],1);
        }
        cout<<ans<<endl;
    }
}