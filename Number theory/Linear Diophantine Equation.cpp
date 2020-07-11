/*
NAME - AMAN JAIN
DATE: 11-07-2020

lINEAR DIOPHANTINE EQUATION->   Ax+ By = C --> {A,B,C are given} FIND THE VALUE OF X AND Y

If gcd(A,B) divides C then there exist  a solution

If solution exist then it can be calculated using extended euclid algo

According to euclid -> Ax1+By1= gcd(A,B)----1

Ax + By =c ----2

we need to convert equation 1 similar to 2
so divide by gcd(A,B) and multiply by c

 Ax1(c)/gcd + By1(c)/gcd =  --- 3

 compare  2 and 3

 x= (x1*c)/gcd
 y= (y1*c)/gcd

 x1 and y1 can be easily calculated using extended euclid  
 
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long


ll x,y,GCD;
void extendedEuclid(ll a,ll b){
  if(b==0){
    x=1;
    y=0;
    GCD=a;
    return;  }
  extendedEuclid(b,a%b);
  ll cX=y;
  ll cY= x-(a/b)*y;
  x=cX; y=cY;
}

ll gcd (ll a, ll b){
    if(b==0)
    return a;

    return gcd(b,a%b);
}

int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    extendedEuclid(a,b);
   
    ll Gcd= gcd(a,b);
  
   
    if(c%Gcd!=0){
        cout<<"No solution";
        return 0;
    }
 

    ll x1= (x)*(c/Gcd);
    ll y1= (y)*(c/Gcd);
    if(a<0)
     x1=-x1;
    if(b<0)
    y1=-y1;

    cout<<x1<<" "<<y1<<endl;


}