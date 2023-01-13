#include <bits/stdc++.h> 

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef pair<int, int> pii;


vector<vector<ll>> edges;
vector<ll> par, needs, vals;

void dfs(ll u, ll p) {
    par[u] = p;

    for (auto v : edges[u]) {
        if (v != p) {
            needs[u]++;
            dfs(v, u);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false), cin.tie(
   __null
   ), cout.tie(
   __null
   );

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        edges = vector<vector<ll>>(n + 1);
        par = vector<ll>(n + 1);
        vals = vector<ll>(n + 1);
        needs = vector<ll>(n + 1);
        for (ll i = 0; i < ll(n - 1); i++) {
            ll x, y;
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        dfs(1, 1);

        ll q;
        cin >> q;

        ll zero = n - 1;
        while (q--) {
            ll t;
            cin >> t;

            if (t == 1) {
                ll u;
                cin >> u;
                if (vals[u] == 0 && needs[u] <= 0) {
                    vals[u] = 1;
                    zero--;
                    needs[par[u]]--;
                }

            } else {
                cout << (zero == -1 ? n - 1 : zero) << '\n';
            }
        }
    }

    return 0;
}