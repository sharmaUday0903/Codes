#include <bits/stdc++.h>
using namespace std;

void processor()
{
    long long out = 0;
    int n;
    cin >> n;
    vector<long long> candies;
    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        candies.push_back(curr);
    }
    long long limit = 1e+9;
    for (long long power = 1; power <= limit; power *= 2)
    {
        long long count = 0;
        for (auto datum : candies)
            if (datum & power)
                count++;
        if (count > 1)
        {
            long long tout = 0;
            out += (count - 1) * power;
            vector<long long> other;
            for (auto datum : candies)
                if ((datum & power) == 0)
                    other.push_back(datum);
                else
                    tout |= datum;
            candies = other;
            candies.push_back(tout);
        }
    }
    if (candies.size() > 1)
        out = -1;
    cout << out << "\n";
    return;
}

/*WhAt ArE dAyS fOr?|----|DaYs ArE wHeRe We LiVe */
/*ThEy CoMe, ThEy WaKe Us|---|TiMe AnD tImE oVeR.*/
/*ThEy--*/ int main()
/*aRe tO*/ {
    /*bE HaP*/ ios_base::sync_with_stdio(false);
    /*pY iN.*/ cin.tie(NULL);
    /*wHeRe */ int count, counter = 0;
    /*cAn wE*/ cin >> count;
    /*lIvE b*/ while (counter++ < count)
    /*Ut dAy*/ {
        processor();
    }
    /*S. aH,*/ return 0;
/*sOlViN*/}
/*g tHaT qUeStIoN bRiNgS tHe PrIeSt AnD tHe DoCt */
/*Or In ThEiR lOnG cOatS RuNnInG oVeR tHe FiElDs.*/