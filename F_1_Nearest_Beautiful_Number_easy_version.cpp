// author : Uday Sharma
// 2022-11-12 02:08:29
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
#define inf 1000000000000000005
#define int long long int


string solve1(string n)
{
 
    int k=n.size();
    string res(k,'9');
    for(char c='8';c>='0';c--)
    {
        string an(k,c);
        if(an>=n)
        {
            res=an;
        }
    }
    return res;
}

string solve2(string n)
{
    string res=solve1(n);
     set<char> s1;
     REP(i,0,n.size())
     {
         s1.insert(n[i]);
     }
     if(s1.size()<=2)
     {  
         return n;
     }
    for(char a='0';a<='9';a++)
    {
        for(char b=a+1;b<='9';b++)
        {
            bool check=true;
            for(int i=0;i<n.size();i++)
            {
                if(n[i]<b)
                {
                    string loc=n;
                    if(loc[i]<a)
                    {
                        loc[i]=a;
                    }
                    else
                    loc[i]=b;
                    for(int j=i+1;j<n.size();j++)
                    {
                        loc[j]=a;
                    }
                    if(res>loc)
                    {
                        res=loc;
                    }
                }
                if(n[i]!=a&&n[i]!=b)
                {
                    check=false;break;
                }
 
            }
            if(check)
            return n;
        }
    }
    return res;
    
}


void solve()
{
    string s;
    int k;
    cin >> s >> k;
    if (k == 1)
    {
        bool u = true;
        char c = s[0];
        REP(i, 1, s.size())
        {
            if (s[i] > s[0])
            {
                u = false;
                break;
            }
        }
        if (u)
        {
            string e(s.size(), c);
            cout << e << endl;
        }
        else
        {
            string e(s.size(), c + 1);
            cout << e << endl;
        }
    }
    else
    {
       cout<<solve2(s)<<endl;

    }
    
}
signed main()
{
    fast;
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}