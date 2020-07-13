/*
Name : Aman Jain
Date : 11-07-2020


Link : https://www.geeksforgeeks.org/friends-pairing-problem/

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll friendsParing(ll dp[],ll n){
  if(n<=2)
  return n;
  if(dp[n]!=0){
      return dp[n];
  }

  ll ans;
  ans=friendsParing(dp,n-1) +(n-1)*friendsParing(dp,n-2);
  dp[n]=ans;
  return dp[n];
}


int main(){
	ll t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll dp[50]={0};
		cout<<friendsParing(dp,n)<<endl;
	}
}