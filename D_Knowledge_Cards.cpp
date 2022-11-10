#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> map;
    int a[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        map[a[i]] = i + 1;
    }
    int idx = 0;
    bool u = true;
    for (int i = k; i >= 1; i--)
    {
        int p = map[i];
        int q = k - i;
        if (p <= idx)
        {
        }
        else
        {
            idx = p;
            int leftover = idx - 1 - q;
            int diff = n * m - 2 - leftover;
            if (diff < 2)
            {
                u = false;
                break;
            }
        }
    }

    u ? cout << "YA\n" : cout << "TIDAK\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}