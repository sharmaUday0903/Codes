/**
 *    author:  tourist
 *    created: 16.02.2023 18:38:42       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) { 
      cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < n; i++) { 
      cin >> b[i];
    }
    multiset<long long> s;
    long long delta = 0;
    for (int i = 0; i < n; i++) {
      s.insert(a[i] - delta);
      long long ans = 0;
      while (!s.empty() && *s.begin() + delta <= b[i]) {
        ans += *s.begin() + delta;
        s.erase(s.begin());
      }
      ans += (long long) s.size() * b[i];
      delta -= b[i];
      cout << ans << " \n"[i == n - 1];
    }
  }
  return 0;
}
