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
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
// Header Files End

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
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
/*

let xor[L..R] be x,
then all a[i] in [L,R] will become x

if we look at the xor of the entire range [l,r], we will have

(prev_xor)^(x^x^..... even number of times)
= (prev_xor).

so, xor of the entire range is not changing.

so, xor should be 0 for ans to exist.

that means, xor[l..r-1] = a[r].

so, if range is odd, we can just choose the entire range.

if range is even:

    
    _ _ _ _ _ _ _ _  






*/
int main() {
    DIVYA;
    ll t, n, i, j, ans, temp, sum,q;
    string sans;
    t = 1;
    // cin >> t;
    while (t--)
    {
        sans = "NO";
        ans = temp = sum = 0;
        cin >> n>>q;
        vll a(n+1,0);
        vll psum(n+1,0);
        vll xor_sum(n+2,0);
        fo(i,1,n)
        {
            cin>>a[i];
            psum[i] = psum[i-1] + a[i];
        }

        for(i = n;i>0;i--)
        {
            xor_sum[i] = (xor_sum[i+1]^a[i]);
        }

        vll nearest(n+1,n+1);

        map<ll,ll>mp_odd,mp_even;
        if(n&1)
        {
            mp_even[0] = n+1;
        }
        else
        {
            mp_odd[0] = n+1;
        }
        for(i = n;i>0;i--)
        {
            if(i&1)
            {
                if(mp_even.find(xor_sum[i]) != mp_even.end())
                {
                    nearest[i] = mp_even[xor_sum[i]] - 1;
                }
                mp_odd[(xor_sum[i])] = i;
            }
            else
            {
                if(mp_odd.find(xor_sum[i]) != mp_odd.end())
                {
                    nearest[i] = mp_odd[xor_sum[i]] - 1;
                }
                mp_even[(xor_sum[i])] = i;
            }
        }
        ll iter;
        fo(iter,1,q)
        {
            ll l,r;
            cin>>l>>r;
            if(psum[r] - psum[l-1] == 0)
            {
                cout<<0<<"\n";
                continue;
            }
            if((xor_sum[l]^xor_sum[r+1]) != 0)
            {
                cout<<-1<<"\n";
                continue;
            }
            if((r-l+1)&1)
            {
                cout<<1<<"\n";
                continue;
            }
            if(a[l] == 0 or a[r] == 0)
            {
                cout<<1<<"\n";
                continue;
            }
            if(nearest[l] <= r)
            {
                cout<<2<<"\n";
            }
            else
            {
                cout<<-1<<"\n";
            }
        }

    }
    return 0;
}






