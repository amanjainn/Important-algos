/*
Name : Aman Jain
Date : 05-07-2020

Question-> Top down approach Fibonacci

Time complexity :  O(n) 
Space Complexity : O(n) (Memoization)

*/

#include<bits/stdc++.h>
using namespace std;


int fibonacci(int n, int dp[]){
  if(n<2)
   return n;

   if(dp[n]!=0)
   return dp[n];

  int ans= fibonacci(n-1,dp)+fibonacci(n-2,dp);
  return dp[n]=ans;
}

int main(){
    int n;
    cin>>n;
    int dp[100]={0};
    cout<<fibonacci(n,dp)<<endl;
}
