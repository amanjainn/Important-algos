/*
 Author : AMAN JAIN
 DATE: 04-07-2020

 PROGRAM ->  Binomial coeffcient using pascal's table (Dynamic programing) 


Time Complexity: O(n*k)
Auxiliary Space: O(n*k)



*/


#include<bits/stdc++.h>
using namespace std;

int binomialCoeff(int n,int k){
    int table[n+1][k+1];
    for(int i=0 ; i<=n ; i++){
        for(int j=0; j<=min(i,k) ;j++){
          if(j==0 || j==i)
            table[i][j]=1;

          else{ //  nCK = [n-1]C[k-1] + [n-1]C[k]
              table[i][j]=table[i-1][j-1] + table[i-1][j];
          }  
        }
    }
    return table[n][k];
}


int main(){
   int n,k;
   cin>>n>>k;
   cout<<"Binomial Coeff is of " <<n<<"C"<<k <<" is "<<binomialCoeff(n,k)<<endl;

}