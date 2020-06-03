// SieveofEratosthenes - Algorithm to find all prime numbers from 1 to n
// Time complexity (nloglogn)
/*
Date : 03-06-20
Author: Aman Jain
*/

#include<bits/stdc++.h>
using namespace std; 
const char nl = '\n';

void IO(){
  #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
 #endif
}


 int is_prime[100000];
 void sieveofEratosthenes(int maxn){

    for(int i=0; i<=maxn ; i++){is_prime[i]=1;}
    is_prime[0]=is_prime[1]=0;

    for(int i=2 ; i*i<maxn  ;i++){
      if(is_prime[i]){
        for(int j= i*i; j<=maxn ; j+=i){
          is_prime[j]=0;
        }
      }
    }
}



int main(){

  IO();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  

  int num;
  cin>>num;

  sieveofEratosthenes(num);
   
   if(is_prime[num])
    cout<<"Yes it is prime";
    else 
    cout<<"No it is not a prime";
  
}