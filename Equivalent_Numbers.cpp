#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPREV(i, k, n) for (int i = n - 1; i >= k; i--)
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int
vector<int> primeFactors(int n)
{
    // Print the number of 2s that divide n
    vi v;
    while (n % 2 == 0)
    {
        // cout << 2 << " ";
        v.pb(2);
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            // cout << i << " ";
            v.pb(i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        // cout << n << " ";
        v.pb(n);

    return v;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int a, b;
        cin >> a >> b;
        vi y = primeFactors(a);
        set<int> s;
        for (auto c : y)
        {
            s.insert(c);
        }
        bool u = true;
        int num = 0;
        int den = 0;
        for (auto c : s)
        {
            int p = c;
            int cnt1 = 0, cnt2 = 0;
            int aa = a;
            int bb = b;
            while (aa % p == 0)
            {
                cnt1++;
                aa /= p;
                /* code */
            }
            while (bb % p == 0)
            {
                cnt2++;
                bb /= p;
                /* code */
            }
            // cout<<cnt1<<" "<<cnt2<<endl;
            if ((cnt1 == 0 && cnt2 != 0) || (cnt1 != 0 && cnt2 == 0))
            {
                u = false;
                break;
            }
            else
            {
                if (num == 0 && den == 0)
                {
                    int yy = __gcd(cnt2, cnt1);
                    num = cnt2 / yy;
                    den = cnt1 / yy;
                    // cout<<num<<" "<<den<<endl;
                }
                else
                {
                    int yy = __gcd(cnt2, cnt1);
                    cnt2 = cnt2 / yy;
                    cnt1 = cnt1 / yy;
                    // cout<<cnt2<<" "<<cnt1<<endl;
                    if (cnt2 != num || cnt1 != den)
                    {
                        u = false;
                        break;
                        /* code */
                    }
                }
            }
        }

        vi x = primeFactors(b);
        set<int> ss;
        for (auto c : x)
        {
            ss.insert(c);
        }
        bool uu = true;
        int numm = 0;
        int denn = 0;
        for (auto c : ss)
        {
            int p = c;
            int cnt1 = 0, cnt2 = 0;
            int aa = a;
            int bb = b;
            while (aa % p == 0)
            {
                cnt1++;
                aa /= p;
                /* code */
            }
            while (bb % p == 0)
            {
                cnt2++;
                bb /= p;
                /* code */
            }
            // cout<<cnt1<<" "<<cnt2<<endl;
            if ((cnt1 == 0 && cnt2 != 0) || (cnt1 != 0 && cnt2 == 0))
            {
                uu = false;
                break;
            }
            else
            {
                if (numm == 0 && denn == 0)
                {
                    int yy = __gcd(cnt2, cnt1);
                    numm = cnt2 / yy;
                    denn = cnt1 / yy;
                    // cout<<num<<" "<<den<<endl;
                }
                else
                {
                    int yy = __gcd(cnt2, cnt1);
                    cnt2 = cnt2 / yy;
                    cnt1 = cnt1 / yy;
                    // cout<<cnt2<<" "<<cnt1<<endl;
                    if (cnt2 != numm || cnt1 != denn)
                    {
                        uu = false;
                        break;
                        /* code */
                    }
                }
            }
        }
        if (!uu || !u)
        {
            cout << "NO\n";
            /* code */
        }
        else
        {
            cout << "YES\n";
        }

        // u ? cout << "YES\n" : cout << "NO\n";
    }
}
