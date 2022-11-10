// author : Uday Sharma
// 2022-11-04 00:25:19
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

bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    bool dp[n + 1][sum + 1];
    REP(i, 0, n + 1)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {

            if (j >= arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
  

    return dp[n][sum];
}
void solve()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    REP(i, 0, n)
    cin >> arr[i];
    isSubsetSum(arr, sum) ? cout << 1 : cout << 0 << endl;
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}