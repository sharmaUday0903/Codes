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
bool canJump(vector<int> &nums)
{
    int n = count(nums.begin(), nums.end(), 0);
    int s = nums.size();
    if (n == 0)
    {
        return true;
    }
    int idx = -1;
    for (int i = s - 1; i >= 0; i--)
    {
        if (nums[i] == 0 && idx == -1)
        {
            idx = i;
        }
        else if (idx != -1)
        {
            int p = idx - i;
            if (p < nums[i])
            {
                idx = -1;
            }
        }
    }
    if (idx == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
signed main()
{
    fast;
    vector<int> nums(5);
    REP(i, 0, 5)
    {
        cin >> nums[i];
    }
    canJump(nums) ? cout << "YES\n" : cout << "NO\n";
}