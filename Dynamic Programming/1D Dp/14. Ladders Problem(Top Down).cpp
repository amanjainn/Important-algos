/*
Name : Aman Jain
Date : 16-07-2020

Question-> https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0

In the given problem we have to find the no. of ways in which we can reach the top of ladder from the bottom, where

n = total number of steps in ladder.
k = maximum numbers of steps that can be taken at a time.



Time complexity :  O(nk) 
Space Complexity : O(n) 
*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long ladders(int n,long long dp[],int k){
    if(n<0)
    return 0;
    if(n==0 || n==1)
    return 1;
    if(dp[n]!=0){
        return dp[n];
    }
    long long  ans=0;
    for(int i=k; i>0 ;i--)
    ans+=ladders(n-i,dp,k);
    dp[n]=ans;
    return dp[n]%mod;
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