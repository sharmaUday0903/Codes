#include<bits/stdc++.h>
 
using namespace std;
 
int const maxn = 1e5 + 5;
int a[maxn];
 
int solve(int n, int x) {
    int res = 0, curr = 0;
    for (int i = 1; i <= n; i++) {
        curr ^= a[i];
        if ((curr|x) == x) curr = 0, res++;
        else {
            if (i == n) return -1;
        }
    }
    return res;
}
 
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = -1;
        ans = max(ans, solve(n, x));
        for (int b = 29; b >= 0; b--) {
            if ((x>>b)&1) {
                int y = (x^(1 << b));
                for (int c = b - 1; c >= 0; c--) {
                    if (((y>>c)&1) == 0) y ^= (1 << c);
                }
                ans = max(ans, solve(n, y));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}