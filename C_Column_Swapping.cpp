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

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, m;
        cin >> n >> m;
        vector<vi> v(n, vi(m));
        vector<vi> srt;
        REP(i, 0, n)
        {
            vi x;
            REP(j, 0, m)
            {
                cin >> v[i][j];
                x.pb(v[i][j]);
            }
            sortv(x);
            srt.pb(x);
        }
        int cnt = 0;
        vi cntt;
        REP(i, 0, m)
        {
            REP(j, 0, n)
            {
                if (v[j][i] != srt[j][i])
                {
                    cnt++;
                    cntt.pb(i);
                    break;
                }
            }
        }
        if (cnt == 0)
        {
            cout << 1 << " " << 1 << endl;
        }
        else if (cnt > 2)
        {
            cout << -1 << endl;
        }
        else
        {
            int p = cntt[0];
            int q = cntt[1];
            REP(j, 0, n)
            {
                swap(v[j][p], v[j][q]);
            }
            if (v==srt)
            {
                cout<<p+1<<" "<<q+1<<endl;
                /* code */
            }
            else
            {
                cout<<-1<<endl;
            }
            
            
        }
    }
}