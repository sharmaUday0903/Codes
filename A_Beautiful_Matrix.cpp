#include<iostream>
using namespace std;

int main(){
    int a[5][5];
    for (int r = 0; r < 5; r++)
    {
        for (int s = 0; s < 5; s++)
        {
            cin>>a[r][s];
        }
    }
    int p,q;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (a[i][j]==1)
            {
                p=i;
                q=j;
                break;
            }
        }
    }
   cout<<abs(2-p)+abs(2-q);
    
    return 0;
}