#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

typedef long long lint;
const lint N = 1e5+7, M = 1e9+7, INF = 1e18;

lint n, k, ans;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
    }
    return res;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--){
		cin >> n >> k;
		
		ans = 1;

		map<lint, lint> primes;

		while (n % 2 == 0){
			primes[2]++;
			n /= 2;
		}

		for (lint i = 3; i * i <= n; i += 2){
			while (n % i == 0){
				primes[i]++;
				n /= i;
			}
		}

		if (n > 1) primes[n]++;

		for (auto p : primes){
			lint pw = (binpow(2, k, M - 1) * p.second + 1)%(M-1);
			lint num = binpow(p.first, pw, M) - binpow(p.first, p.second, M) + M;
			lint den = binpow(p.first - 1, M - 2, M);
			lint prod = (num * den)%M;
			ans = (ans * prod)%M;
		}
				

		cout << ans << '\n';
	}
	return 0;
}