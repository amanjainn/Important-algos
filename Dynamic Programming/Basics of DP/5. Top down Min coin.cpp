/*
Name : Aman Jain
Date : 05-07-2020

Question-> Top down Min coins to change

Time complexity :  O(n*t) 
Space Complexity : O(n) 
*/
#include<bits/stdc++.h>
using namespace std;


int minCoins(int dp[],int coins[],int t, int n){
    if(n==0)
     return 0;
    if(dp[n]!=0)
     return dp[n];
   int ans=INT_MAX;
   for(int i=0 ; i<t ; i++){
       if(n-coins[i]>=0){
          int subproblem=minCoins(dp,coins,t,n-coins[i]);
          ans=min(subproblem+1,ans);
       }
   }   
    dp[n]=ans;
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



