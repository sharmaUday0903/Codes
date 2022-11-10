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
        long long int a[n];
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long int max_element = max(a[0] * a[0], a[n - 1] * a[n - 1]);
        long long int min_element = INT64_MAX;
        if (a[0] < 0 && a[n - 1] > 0)
        {
            min_element = a[0] * a[n - 1];
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                min_element = min(min_element, a[i] * a[i]);
            }
        }
        cout << min_element << " " << max_element << endl;
    }
    return 0;
}