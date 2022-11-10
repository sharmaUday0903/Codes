#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        int g = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            g = __gcd(g, a[i]);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int p = __gcd(p, a[i]);
            if (g == p)
            {
                count++;
                p = 0;
            }
        }
        if (count >= k)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}