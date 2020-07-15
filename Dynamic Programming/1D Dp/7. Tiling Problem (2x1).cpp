/*
Name : Aman Jain
Date : 11-07-2020

Question-> Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.

Algorithm= Solving the recurrence -> T(n)=T(n-2)+T(n-1) {n<=2 => n}

Time Complexity :O(n)

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll  tilingProb(ll n, ll dp[]){
    if(n<=2)
    return n;
    if(dp[n]!=0)
    return dp[n];

   dp[n]=  tilingProb(n-1,dp)+ tilingProb(n-2,dp);
   return dp[n];
}
int main(){
    ll n;
    cin>>n;
    ll dp[100005]={0};
    cout<<tilingProb(n,dp);
}