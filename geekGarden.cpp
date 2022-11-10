// author : Uday Sharma
// 2022-11-01 22:11:37
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
const int N = 105;
int n, m;
char a[N][N];
int ans = 0;
int c = 0;
void garden(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '0')
        return;
    if (a[i][j] == '1')
    {
        c++;

        a[i][j] = '0';

        garden(i - 1, j);
        garden(i + 1, j);
        garden(i, j + 1);
        garden(i, j - 1);
        garden(i - 1, j - 1);
        garden(i + 1, j - 1);
        garden(i - 1, j + 1);
        garden(i + 1, j + 1);
    }
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {

        cin >> n >> m;
        REP(i, 0, n)
        {
            REP(j, 0, m)
            {
                cin >> a[i][j];
            }
        }
        ans = 0;
        REP(i, 0, n)
        {
            REP(j, 0, m)
            {
                if (a[i][j] == '1')
                {
                    c = 0;
                    garden(i, j);
                    ans = max(ans, c);
                }
            }
        }
        cout<<ans<<endl;
    }
}