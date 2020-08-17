/*
Time complexity- O(N^3)
Space Complexity- O(N^2)
*/


#include<bits/stdc++.h>
using namespace std;

long long matrixChainMultiplication(int mat[],int i, int j,long long dp[][101]){
    if(i==j){
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=-1)
            return dp[i][j];

    long long ans=INT_MAX;
    for(int k=i; k<j ; k++){
        long long temp=matrixChainMultiplication(mat,i,k,dp)+ matrixChainMultiplication(mat,k+1,j,dp)+ mat[i-1]*mat[k]*mat[j];
        ans=min(temp,ans);
    }        
    dp[i][j]=ans;
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mat[n];
        for(int i=0;i<n;i++)cin>>mat[i];
        long  long dp[101][101];
        memset(dp,-1,sizeof(dp));
        cout<<matrixChainMultiplication(mat,1,n-1,dp)<<endl;
    }
}
