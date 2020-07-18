#include<bits/stdc++.h>
using namespace std;

#define ll long long


ll inverseMod(ll a, ll m) 
{   ll m0 = m, t, q; 
    ll x0 = 0, x1 = 1;  
    if (m == 1) 
       return 0; 
    while (a > 1) 
    { 
        q = a / m; 
        t = m; 
        m = a % m, a = t; 
        t = x0; 
        x0 = x1 - q * x0; 
        x1 = t; 
    } 
    if (x1 < 0) 
       x1 += m0;  
    return x1; 
} 

ll chineseRem(ll num[],ll rem[],int n){
    ll N=1;
    for(int i=0;  i<n  ;i++){
        N*=num[i];
    }
    ll result=0;
    for(int i=0; i<n ; i++){
        ll ni=N/num[i];
        ll inve=inverseMod(ni,num[i]);
        cout<<inve<<endl;
        result+=(rem[i]*ni*inve);
    }
    return result%N;
}
int main(){
    int n;
    cin>>n;
    ll num[n];
    for(int i=0; i<n ;i++){
        cin>>num[i];
    }
    ll rem[n];
    for(int i=0; i<n ; i++){
        cin>>rem[i];
    }
    cout<<chineseRem(num,rem,n);
}