/*
Name : Aman Jain
Date : 16-07-2020

Question-> https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0

In the given problem we have to find the no. of ways in which we can reach the top of ladder from the bottom, where

n = total number of steps in ladder.
k = maximum numbers of steps that can be taken at a time.

The recurrence can be written as T[n]= 2*T[n-1]-T[n-k]
Time complexity :  O(n+k) 
Space Complexity : O(n) 

*/

/*
Name : Aman Jain
Date : 16-07-2020

Question-> https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0

In the given problem we have to find the no. of ways in which we can reach the top of ladder from the bottom, where

n = total number of steps in ladder.
k = maximum numbers of steps that can be taken at a time.

The recurrence can be written as T[n]= 2*T[n-1]-T[n-k]
Time complexity :  O(n+k) 
Space Complexity : O(n) 

*/


#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long ladders(int n,long long dp[],int k){
    dp[0]=dp[1]=1;
    for(int i=2; i<=k ; i++){
        dp[i]=(2*dp[i-1]);
    }

    for(int i=k+1 ;i<=n ; i++){
        dp[i]=((2*dp[i-1]%mod)-(dp[i-k-1]%mod))%mod;
    }
    return dp[n];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        long long dp[100005]={0};
        cout<<ladders(n,dp,k)<<endl;
    }
}