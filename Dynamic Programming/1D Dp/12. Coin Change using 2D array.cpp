

/*
Name : Aman Jain
Date : 11-07-2020

Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

https://www.geeksforgeeks.org/coin-change-dp-7/


For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.


Time Complexity: O(mn)


*/

#include<bits/stdc++.h>
using namespace std;

int countways(int coins[],int m,int n){
    int table[m][n+1];
    for(int i=0; i <m ;i++){
        table[i][0]=1;
    }
    
    for(int i=0; i <m ;i++){
        for(int j=1 ;j<=n ;j++ ){
            int x=(j-coins[i]>=0)?table[i][j-coins[i]] : 0;
            int y=(i>=1)?table[i-1][j]:0;
            table[i][j]=x+y;
        }
    }
  
 return table[m-1][n];
}


int main(){
    int  n,m;
    cin>>n>>m;
    int coins[m];
    for(int i=0 ; i<m ; i++){
        cin>>coins[i];
    }
    cout<<countways(coins,m,n)<<endl;
}