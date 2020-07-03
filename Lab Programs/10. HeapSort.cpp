/*
 Author : AMAN JAIN
 DATE: 04-07-2020

 PROGRAM ->  Heap sort
  
 Heap Sort is O(nLogn).  
 
 In heap sort we use max heap for sorting in ascending order otherwise we use min heap for sorting in descending order. 

 Heapify function is use to refrator the heap to eith max heap or min heap . It takes time complexity O(logn)


*/

#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr, int n){
    for(int i=0; i<n ;i++)
      cout<<arr[i] <<" ";
   
   cout<<endl;  
}



void heapify(int *arr, int n, int root){
    int largest= root; //Initially assume root to be the largest
    int leftchild=2*root+1;
    int rightchild=2*root+2;


    //We need the find the largest node among root,left,right child

    if(leftchild<n && arr[leftchild]>arr[largest])
        largest=leftchild;

    
    if(rightchild<n && arr[rightchild]>arr[largest])
       largest=rightchild;

    //If the largest node is not root then we need to change the position of the root with the largest node and recursively perform the same for the rest of the subtree

     if(largest!=root){
         swap(arr[largest],arr[root]);
         heapify(arr,n,largest);
     }  
}

void heapsort(int *arr, int n){
    for(int i =n/2-1 ;i>=0 ; i--)
       heapify(arr,n,i);  //Make max heap

    //   Remove the max element from the heap
    for(int i=n-1; i>0 ;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    } 
}


int main(){
    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0 ;i<n ; i++){
        cin>>arr[i];
    }
    heapsort(arr,n);
    printArray(arr,n);
}