#include<bits/stdc++.h>
using namespace std;

bool comp(pair<long long,long long>&P,pair<long long,long long>&Q){
    long long t1 = P.first + P.second;
    long long t2 = Q.first + Q.second;
    if(t1 == t2)return P.first<Q.first;
    return t1<t2;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        
        long long A[n];
        for(int i=0;i<n;++i)cin>>A[i];
        
        long long B[n];
        for(int i=0;i<n;++i)cin>>B[i];
        
        vector<pair<long long,long long>>P;
        for(int i=0;i<n;++i){
            P.push_back({A[i],B[i]});
        }
        
        sort(P.begin(),P.end(),comp);
        
         
        int ans = 0;
        long long cur = k;
        long long mx = 0;
        int i;
        for(i=0;i<n;++i){
            long long sum = P[i].first + P[i].second;
            if(cur >= sum){
                ans++;
                mx = max(mx,P[i].second);
                cur -= sum;
            }
            else {
                break;
            }
        }
        
        for(;i<n;++i){
            if(cur >= P[i].first){
                //this is our last eleent
                ans++;
                break;
            }
            else{
                //we add the biggest second value element at the end and takig this into account
                long long sum = cur - (P[i].first + P[i].second);
                sum += mx;
                
                if(sum>=0){
                    ans++;
                    break;
                }
            }
        }
        
         
        
        cout<<ans<<"\n";
    }
}