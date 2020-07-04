/*
 Author : AMAN JAIN
 DATE: 04-07-2020

 PROGRAM ->  Knapsack Dp


Time Complexity: O(N*W).
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W).
The use of 2-D array of size ‘N*W’.
*/

#include<bits/stdc++.h>
using namespace std;


int knapsack(int weights[], int profits[],int objects, int capacity){
   int sack[objects+1][capacity+1];

    for(int i=0 ; i<=objects ; i++){
       for(int j=0; j<=capacity ;j++){
           if(i==0 || j==0)
              sack[i][j]=0;

           else if(weights[i-1]<=j)
            sack[i][j]=max(profits[i-1]+sack[i-1][j-weights[i-1]],sack[i-1][j]);

            else
             sack[i][j]=sack[i-1][j];
       }
    }
    return sack[objects][capacity];
}


int main(){
    int objects,capacity;
    cout<<"Enter the capacity"<<endl;
    cin>>capacity;
    cout<<"Enter the number of objects"<<endl;
    cin>>objects;
    int *profits= new int[objects];
    int *weights= new int[objects];

    cout<<"Enter the weight and profits"<<endl;
    for(int i=0; i<objects ;i++){
        cin>>weights[i]>>profits[i];
    }
    cout<<knapsack(weights,profits,objects,capacity)<<endl;
}
