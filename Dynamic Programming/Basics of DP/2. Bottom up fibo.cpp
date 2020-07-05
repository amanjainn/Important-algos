/*
Name : Aman Jain
Date : 05-07-2020

Question-> Bottom up approach Fibonacci

Time complexity :  O(n) 
Space Complexity : O(n) 
*/

#include<bits/stdc++.h>
using namespace std;


int fibonacci(int n, int dp[]){
   dp[1]=1;
   for(int i=2; i<=n ; i++){
       dp[i]=dp[i-1]+dp[i-2];
   }
   return dp[n];
}

int main(){
    int n;
    cin>>n;
    int dp[100]={0};
    cout<<fibonacci(n,dp)<<endl;
}
