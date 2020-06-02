// Matrix exponentiation - SPOJ (SEQ)
/*
Date : 02-06-20
Author: Aman Jain
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000

ll k;
vector<ll> b,c;

vector<vector<ll>> multiply(vector<vector<ll>>A, vector<vector<ll>> B){
  vector<vector<ll>> C(k+1,vector<ll>(k+1));
  for(int i=1; i<=k ;i++){
    for(int j=1; j<=k ; j++){
      for(int x=1; x<=k ; x++){
        C[i][j]= (C[i][j]+ (A[i][x]*B[x][j])%mod)%mod;
      }
    }
  }
  return C;
}


vector<vector<ll>> pow (vector<vector<ll>> T, ll n){
  if(n==1)
   return T;

   if(n & 1){
     return multiply(T,pow(T,n-1));
   }
     vector<vector<ll>> x= pow(T,n/2);
     return multiply(x,x);
}

// Function to compute matrix exponentiation
ll compute(int n){
// Invalid case
  if(n==0){
    return 0;
  }
// Base case
  if(n<=k){
    return b[n-1];
  }
// Matrix exponentiation
  vector <ll> f1(k+1);
  for(int i=1 ;i<=k ;i++){
    f1[i]=b[i-1];
  }
//  Transformation matrix
vector<vector<ll>> T(k+1,vector<ll>(k+1));
for(int i=1; i<=k ;i++){
  for(int j=1; j<=k ; j++){
    if(i<k){
      if(j==i+1){
        T[i][j]=1;
      }else{
        T[i][j]=0;
      }
    }else{
      T[i][j]=c[k-j];
    }
  }}
// Calculating pow of transformation matrix
T=pow(T,n-1);

//Calculating fn = T^(n-1) * f1;

ll res=0;
for(int i=1 ;i<=k ;i++){
 res= (res + (T[1][i] * f1[i] %mod))%mod;
}

return res;
}


int main(){

  int t;
  cin>>t;
  while(t--){

    cin>>k;
    for(int i=0; i<k ; i++){
      int num;
      cin>>num;
      b.push_back(num);
    }

    for(int i=0; i<k ; i++){
      int num;
      cin>>num;
      c.push_back(num);
    }
    int n;
    cin>>n;
    cout<<compute(n)<<endl;

    b.clear();
    c.clear();
  }
}
