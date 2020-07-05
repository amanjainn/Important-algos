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
  int ans=0;
  for(int i=2 ; i<= n ;i++){
  int ob1=INT_MAX,ob2=INT_MAX,ob3=INT_MAX;
      if(i%2==0){
          ob1=dp[i/2]+1;
      }
      
      if(i%3==0){
          ob2=dp[i/3]+1;
      }
      ob3=dp[i-1]+1;
      ans= min(min(ob1,ob2),ob3);
      dp[i]=ans;
  }
  return dp[n];

}

int main(){
    int n;
    cin>>n;
    int dp[100]={0};
   cout<<minStepsToOne(n,dp)<<endl;
}