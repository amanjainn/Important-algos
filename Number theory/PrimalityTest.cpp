// Primality Test (Find whether a number is prime)
// Time complexity (sqrt(N))
/*
Date : 03-06-20
Author: Aman Jain
*/

#include<bits/stdc++.h>
using namespace std; 


void IO(){
  #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
 #endif
}

 bool isPrime(int num){
   if(num==1)
    return false;

    for(int i=2 ; i*i<num ; i++)
      if(num%i==0)
       return false;  

    return true;
 }



int main(){

  IO();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  int num;
  cin>>num;

  if(isPrime(num)){
    cout<<"Number is prime";
  }else  {
    cout<<"Number is not prime";
  }
  

  
}