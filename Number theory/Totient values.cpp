// Totient Values : Generate totient values from 1 to n
// Time complexity (nloglogn)
/*
Date : 18-07-20
Author: Aman Jain
*/



#include<bits/stdc++.h>
using namespace std;

vector<int> totientValues(int n){
    vector<int> ttv(n+1);
    for(int i=2;i <=n ; i++)
    ttv[i]=i;

    ttv[0]=0;
    ttv[1]=1;

    for(int i=2 ; i <= n;i++){
        if(ttv[i]==i)
        for(int j=i ;j<=n ; j+=i){
            ttv[j]-=ttv[j]/i;
        }
    }

  return ttv;

}
int main(){
    int n;
    cin>>n;
    vector<int> totient=totientValues(n);
    for(int x: totient){
        cout<<x<<" ";
    }
}