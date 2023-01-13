//****************************Template Begins****************************//

// Header Files
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>

// Header Files End

using namespace std;

// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define DIVYA ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(i=a;i<=b;i++)
#define all(v) (v).begin(),(v).end()
#define all1(v) (v).begin()+1,(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define allr1(v) (v).rbegin()+1,(v).rend()
#define sort0(v) sort(all(v))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
#define sz(x) (ll)x.size()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005
const ll mod = 1e9 + 7;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
//****************************Template Ends*******************************//

int main() {
    DIVYA;
    ll t, n, i, j, ans, temp, sum,k,d;
    string sans;
    t = 1;
    // cin >> t;
    while (t--)
    {
        sans = "NO";
        ans = temp = sum = 0;
        cin >> n>>k>>d;
        vll police(n+1,0);
        fo(i,1,k)
        {
            ll x;
            cin>>x;
            police[x]++;
        }
        vector<vector<pll>>adj(n+1);
        fo(i,1,n-1)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].pb({v,i});
            adj[v].pb({u,i});
        }
        queue<ll>q;
        vector<bool> ansvec(n+1,false);
        vll par(n+1,0);
        vector<bool>vis(n+1,false);
        fo(i,1,n)
        {
            if(police[i])
            {
                q.push(i);
                vis[i] = true;
            }
        }
        while(sz(q))
        {
            ll tp= q.front();
            q.pop();
            for(auto x : adj[tp])
            {
                if(x.first == par[tp])continue;
                if(vis[x.first])
                {
                    ansvec[x.second] = true;
                }
                else
                {
                    vis[x.first] = true;
                    q.push(x.first);
                    par[x.first] = tp;
                }
            }
        }
        fo(i,1,n)
        {
            if(ansvec[i])ans++;
        }
        cout<<ans<<"\n";
        fo(i,1,n)if(ansvec[i])cout<<i<<" ";
    }
    return 0;
}






