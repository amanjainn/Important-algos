
/*
Name : Aman Jain
Date : 11-07-2020


Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. 
Time Complexity :O(logn)

*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll binaryStrings(ll n, ll dp[]){
    if(n<1)
    return 0;
    if(n==1)
    return 2;
    if(n==2)
    return 3;
   
    if(dp[n]!=0)
    return dp[n];

    dp[n]=binaryStrings(n-1,dp)+ binaryStrings(n-2,dp);
  return dp[n];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll dp[1000]={0};
        cout<<binaryStrings(n,dp)<<endl;
    }
}