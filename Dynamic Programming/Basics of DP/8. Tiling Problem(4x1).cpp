/*
Name : Aman Jain
Date : 11-07-2020

Given a tile of size 1 x 4, how many ways you can construct a grid of size N x 4.
Algorithm= Solving the recurrence -> T(n)=T(n-4)+T(n-1) {n<=3 => 1 & n==4 => 2}

Time Complexity :O(n)

*/



#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll  tilingProb(ll n, ll dp[]){
    if(n<=3)
    return 1;
    if(n==4)
    return 2;
    if(dp[n]!=0)
    return dp[n];

   dp[n]=  tilingProb(n-1,dp)+ tilingProb(n-4,dp);
   return dp[n];
}
int main(){
    ll n;
    cin>>n;
    ll dp[100005]={0};
    cout<<tilingProb(n,dp);
}