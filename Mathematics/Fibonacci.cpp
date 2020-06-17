#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define mod 1000000007

vector<vector<ll>> multiply(vector<vector<ll>>A, vector<vector<ll>>B){
	vector<vector<ll>> C(2,vector<ll>(2));
	for(int i=0 ; i<2; i++){
		for(int j=0; j<2; j++){
         for(int x=0; x<2 ;x++){
			 C[i][j]=(C[i][j] + (A[i][x]*B[x][j])%mod)%mod;
		 }
	   }
	}
	return C;
}

vector<vector<ll>> matpow(vector<vector<ll>> a,ll pow){
	if(pow==1)
	return a;

    if(pow&1){
		return multiply(a,matpow(a,pow-1));
	}else{
		vector<vector<ll>> x= matpow(a,pow/2);
		return multiply (x,x);
	}
}

int main(){
   int t;

   cin>>t;
   while(t--){
	   ll n;
	   cin>>n;
	   n++;
	   if(n<3)
	   cout<<"1"<<endl;
	   else{
	   vector<vector<ll>> T(2,vector<ll>(2));
	   T[0][0]=0;
	   T[0][1]=1;
	   T[1][0]=1;
	   T[1][1]=1;

	   T= matpow(T,n-1);
	   vector<int> F1;
	   F1.push_back(0);
	   F1.push_back(1);
     ll res=0;

	   for(int i=0 ; i<2 ;i++){
		   res= (res + (T[0][i] * F1[i])%mod)%mod;
	   }

     	cout<<res<<endl;
	   }
   }
}
