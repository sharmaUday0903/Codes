#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, q;
    cin >> n >> a >> q;
    int b = a;
    string s;
    cin >> s;
    if (n == b)
        cout << "YES\n";
    else
    {
        for (int i = 0; i < q; i++)
        {
            if (s[i] == '+')
            {
                a += 1;
                b++;
            }
            else if (s[i] == '-')
                a -= 1;

            if (a >= n)
            {
                cout << "YES\n";
                return;
            }
        }
        if (b >= n)

            cout << "MAYBE\n";
        else
            cout << "NO \n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}