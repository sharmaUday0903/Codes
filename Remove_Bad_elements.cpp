#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int o = n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int max_c = 1, res = a[0], c = 1;
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
                c++;
            else
                c = 1;
            if (c > max_c)
            {
                max_c = c;
                res = a[i];
            }
        }
        int max = 0;
        for (int j = 0; j < n; j++)
        {
            if (res == a[j])
            {
                max++;
            }
        }
        if (o == max)
        {
            cout << 0 << endl;
        }
        else
            cout << o - max << endl;
    }
    return 0;
}