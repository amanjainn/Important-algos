/*
Name : Aman Jain
Date : 05-07-2020

Question-> Top down Min steps to one

n-> 
1. n-1
2. n/2 -> (If n is a multiple of 2)
3. n/3 -> (If n is a multiple of 3)

Time complexity :  O(n) 
Space Complexity : O(n) 
*/

#include<bits/stdc++.h>
using namespace std;


int minStepsToOne(int n,int dp[]){
   if(n==1)
    return 0;
   
   if(dp[n]!=0){
       return dp[n];
   }
  
  int op1,op2,op3;
  op1=op2=op3=INT_MAX;

  if(n%3==0){
      op1=minStepsToOne(n/3,dp)+1;
  }

  if(n%2==0){
      op2=minStepsToOne(n/2,dp)+1;
  }
  op3=minStepsToOne(n-1,dp)+1;
  
  int ans= min(min(op1,op2),op3);
  return dp[n]=ans;
}

int main(){
    int n;
    cin>>n;
    int dp[100]={0};
   cout<<minStepsToOne(n,dp)<<endl;
}