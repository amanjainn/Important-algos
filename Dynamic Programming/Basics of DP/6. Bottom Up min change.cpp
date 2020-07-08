/*
Name : Aman Jain
Date : 05-07-2020

Question-> Bottom Up  Min coins to change

Time complexity :  O(n*t) 
Space Complexity : O(n) 
*/
#include<bits/stdc++.h>
using namespace std;

int minCoins(int dp[],int coins[],int t, int n){
    for(int i=1; i <=n ; i++){
        int subprob=INT_MAX;
        for(int j=0 ; j<t; j++){
            if(i-coins[j]>=0)
               subprob=min(subprob,dp[i-coins[j]]+1);
        }
      
    dp[i]=subprob;
    }
    return dp[n];
}
int main(){
    int n,t;
    cin>>n>>t;
    int coins[t];
    for(int i=0 ; i<t; i++){
        cin>>coins[i];
    }
    int dp[100]={0};
    cout<<minCoins(dp,coins,t,n);
}



