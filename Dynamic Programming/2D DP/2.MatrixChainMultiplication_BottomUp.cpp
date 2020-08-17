/*
Time complexity- O(N^3)
Space Complexity- O(N^2)

*/


#include<bits/stdc++.h>
using namespace std;

long long matrixChainMultiplication(int mat[],int n){
    long long dp[101][101];
    for(int i=1; i<n ; i++){
        dp[i][i]=0;
    }
    for(int l=2; l<n; l++){
        for(int i=1;i<=n-l ; i++){
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i ;k<j ;k++){
                dp[i][j]=min(dp[i][k]+dp[k+1][j]+mat[i-1]*mat[k]*mat[j],dp[i][j]);
            }
        }
    }
    return dp[1][n-1];
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mat[n];
        for(int i=0;i<n;i++)cin>>mat[i];
        cout<<matrixChainMultiplication(mat,n)<<endl;
    }
}
