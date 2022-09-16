// a  b  c  d

// c>a b>d

// we can use n^2 app  

// 5000*5000  = 2.5 * 10^7
 

//  1 2 3 4 5 6 67

#include<bits/stdc++.h>
using namespace std;
int br[5001][5001];  // stores number of elem that are less in front
int cr[5001][5001];// stores number of elem that are less in back
int main()
{
    int t;cin>>t;
    int ar[5001];
    while(t--)
    {
        int n;cin>>n;
        for(int i=0;i<n;i++)
        {
            ar[i]=br[i][n-1]=cr[i][0]=0;
        }
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        for(int i=n-1;i>-1;i--)
        {
            for(int j=i-1;j>-1;j--)
            {
                if(ar[i]>ar[j])
                {
                    br[i][j]=br[i][j+1]+1;  //c>a
                }
                else{
                    br[i][j]=br[i][j+1];
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(ar[i]>ar[j])
                {
                    cr[i][j]=cr[i][j-1]+1;
                }
                else
                {
                    cr[i][j]=cr[i][j-1];
                }
            }
        }

        int64_t ans=0;

        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                ans+=((br[j][0]-br[j][i])*(cr[i][n-1]-cr[i][j]));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
