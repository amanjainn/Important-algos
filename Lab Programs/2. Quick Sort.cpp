/*
 Author : AMAN JAIN
 DATE: 03-07-2020

 PROGRAM ->  Quick Sort

Time complexity :  Overall Time complexity O(nlogn)

1. Best Case O(nlogn) (where n is the size of the array) ->  When array is not random
2. Worst Case O(n*n) (Where n is the  size of the array)  ->  When array is sorted increasingly or decreasingly

*/


#include<bits/stdc++.h>
using namespace std;



void printArray(int *arr, int n){
    for(int i=0 ; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// Taking last element as pivot

// int partition1(int *arr,int low,int high){
//     int pivot=high;
//     int j=low-1;
//     for(int i=low ; i<=high-1 ;i++){
//         if(arr[pivot]>arr[i]){
//             j++;
//             swap(arr[j],arr[i]);

//         }
//     }
//     swap(arr[j+1],arr[pivot]);
//     return j+1;
// }

// Taking first element as pivot

int partition1(int *arr,int start,int end){
  int pivot=arr[start],p1=start+1,i,temp;

for(i=start+1;i<=end;i++){

if(arr[i]<pivot) {
      if(i!=p1){
        swap(arr[p1],arr[i]);
      }
          p1++;
    }
}
swap(arr[start],arr[p1-1]);
return p1-1;
}



void Quicksort(int *arr, int low, int high){

    if(low<high){
        int p=partition1(arr,low,high);
        Quicksort(arr,low,p-1);
        Quicksort(arr,p+1,high);
    }
}

int main(){
    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0 ; i<n; i++){
        cin>>arr[i];
    }

    int low=0;
    int high=n-1;
    Quicksort(arr,low,high);

    printArray(arr,n);

}
