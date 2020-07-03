/*
 Author : AMAN JAIN
 DATE: 03-07-2020

 PROGRAM ->  Merge Sort

Time complexity :  Overall Time complexity O(nlogn)

1. Best Case O(nlogn) (where n is the size of the array) - Space Complexity O(n)
2. Worst Case O(nLogn) (Where n is the  size of the array)  - Space Complexity O(n)

*/


#include<bits/stdc++.h>
using namespace std;


void printArray(int *arr, int n){
    for(int i=0 ; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void merge1(int *arr, int low,int mid, int high){
   int i,j,k;
   int n1=mid-low+1;
   int n2=high-mid;
   int L[n1],R[n2];
   for(int i=0 ; i<n1; i++){
       L[i]=arr[i+low];
   }
   for(int i=0; i<n2 ; i++){
       R[i]=arr[mid+1+i];
   }

 i =0;
 k=low;
 j=0;

   while(i<n1 && j<n2){
       if(L[i]>R[j]){
           arr[k]=R[j];
           j++;
       }else{
           arr[k]=L[i];
           i++;
       }
       k++;
   }

   while(i<n1){
       arr[k]=L[i];
       i++;
       k++;
   }

   while(j<n2){
       arr[k]=R[j];
       j++;
       k++;
   }
}

void mergeSort(int *arr, int low, int high){
    if(low<high){
        int m=(low+high)/2;
        mergeSort(arr,low,m);
        mergeSort(arr,m+1,high);
        merge1(arr,low,m,high);
    }
}


int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    printArray(arr,n);
}
