/*
Name : Aman Jain
Date : 05-07-2020

Question-> Bottom Up  Min coins to change

Time complexity :  O(n*t) 
Space Complexity : O(n) 
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,p;
    cin>>n>>p;
    int coins[p];
    for(int i=0; i<p ;i++){
        cin>>coins[i];
    }
    sort(coins,coins+p);
    int dp[1000001]={0};
    for(int i=1; i<=100000 ;i++){
        dp[i]=INT_MAX;
    }
    int ans=0;
    for(int i=1; i<=n ; i++){
        ans=0;
        for(int j=0 ; j<p ; j++){
            if(i-coins[j]>=0){
                ans=dp[i-coins[j]];
                if(ans!=INT_MAX){
                    ans=ans+1;
                }
                dp[i]=min(ans,dp[i]);
            }
        }  
    }
    if(dp[n]!=INT_MAX)
    cout<<dp[n]<<endl;
    else{
        cout<<"-1"<<endl;
    }
  }
}


