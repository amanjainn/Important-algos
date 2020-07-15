/*
Name : Aman Jain
Date : 15-07-2020

Question-> https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

Time complexity :  O(n) 
Space Complexity : O(1) 
*/



#include<bits/stdc++.h>
using namespace std;

long long kandaneAlgo(long long *arr, int n){
    long long curr_sum=arr[0];
    long long max_sum=arr[0];
    long long previous_sum=arr[0];
    for(int i=1; i<n ;i++){
        curr_sum=previous_sum+arr[i];
        previous_sum=max(arr[i],curr_sum);
        max_sum=max(previous_sum,max_sum);
    }
    return max_sum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    cout<<kandaneAlgo(arr,n)<<endl;
    }
}