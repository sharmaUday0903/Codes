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

string decToBinary(int n)
{
    string ans = "";
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0)
    {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    int pp = 0;
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
    {
        // ans = ans * 10 + binaryNum[j];
        char c = 48 + binaryNum[j];

        ans += c;
    }
    // cout << binaryNum[j];

    return ans;
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
        int ans = b - a;
        string aa = decToBinary(a);
        string bb = decToBinary(b);
        int l = bb.length() - aa.length();
        reverse(bb.begin(), bb.end());
        REP(i, 0, l)
        {
            bb.pop_back();
        }
        reverse(bb.begin(), bb.end());
        int N, decimal_number1 = 0, p = 0;
        N = aa.size();                   // storing the size of string in N
        for (int i = N - 1; i >= 0; i--) // starting the loop from LSB
        {
            if (aa[i] == '1') // Checking if string element is 1
            {
                decimal_number1 += pow(2, p); // if yes, adding the pth power of 2 to the decimal_number
            }
            p++; // incrementing the value of p as we move towards MSB
        }
        // int N, decimal_number2 = 0, p = 0;
        int decNum = 0;
        p = 0;
        N = bb.size();                   // storing the size of string in N
        for (int i = N - 1; i >= 0; i--) // starting the loop from LSB
        {
            if (bb[i] == '1') // Checking if string element is 1
            {
                decNum += pow(2, p); // if yes, adding the pth power of 2 to the decimal_number
            }
            p++; // incrementing the value of p as we move towards MSB
        }
        // cout << decNum << endl;

        // cout << bb << endl;
        int ans1=abs(decimal_number1-decNum);
        ans1++;
        cout<<min(ans,ans1)<<endl;
    }
}