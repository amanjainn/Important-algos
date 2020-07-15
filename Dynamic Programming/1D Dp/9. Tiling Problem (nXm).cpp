/*
Name : Aman Jain
Date : 11-07-2020


Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.

Time Complexity :O(n)

*/

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
ll pilingProb(ll n,ll m, ll dp[]){
	if(n==m)
	  return 2;
	if(n<m)
	  return 1;

	if(dp[n]!=0)
	return dp[n];

	dp[n]=pilingProb(n-1,m,dp)+ pilingProb(n-m,m,dp);

	return (dp[n]%mod);  
}
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll dp[100005]={0};
		cout<<pilingProb(n,m,dp)<<endl;
	}
}