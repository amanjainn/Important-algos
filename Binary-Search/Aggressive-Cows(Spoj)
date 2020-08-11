#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool checkDiff(ll stalls[],ll diff, ll C, ll N){
     ll count=1;
     ll prev=stalls[0];
     for(int i=1; i<N;i++){
         if(stalls[i]-prev>=diff){
             count++;
             prev=stalls[i];
         }
         if(count==C)
         return true;
     }
   
     return false;
}


ll largestminimum(ll stalls[],ll C, ll N){
     ll low=1;
     ll high=stalls[N-1];
     ll ans=0;
     while(low<=high){
         ll mid=low+(high-low)/2;
         if(checkDiff(stalls,mid,C,N)){
             ans=mid;
             low=mid+1;
         }else{
             high=mid-1;
         }
     }
     return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    ll N,C;
    cin>>N>>C;
    ll stalls[N];
    for(int i=0; i<N; i++){
        cin>>stalls[i];
    }
    sort(stalls,stalls+N);
    cout<<largestminimum(stalls,C,N)<<endl;
    }
}
