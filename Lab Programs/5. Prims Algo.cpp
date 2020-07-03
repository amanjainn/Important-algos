
/*
 Author : AMAN JAIN
 DATE: 03-07-2020

 PROGRAM ->  Prims Algo

Time Complexity of the below program is O(V^2). 

*/

#include<bits/stdc++.h>
using namespace std;


int minnode(int node[], bool visited[], int V){
   int min =INT_MAX,index;
   for(int i =0 ;i<V; i++){
       if(visited[i]==false && node[i]<min){
         min=node[i];
         index=i;
       }
   }
   return index;
}

void prims(int graph[][100], int V){

     int tree[V];  //To store the tree
     int weight[V];   // to pick minimum node
     bool visited[V];  // to check if a node is visited or not

     for(int i=0;i<V; i++){
         weight[i]=INT_MAX;
         visited[i]=false;
     }
     
     weight[0]=0;
     tree[0]=-1;

     for(int i=0 ;i<V-1 ;i++){
         
          int u=minnode(weight,visited,V);
          visited[u]=true;

          for(int i=0 ;i<V; i++){
              if(graph[u][i]!=0 &&visited[i]!=true && graph[u][i]<weight[i]){
                tree[i]=u;
                weight[i]=graph[u][i];
              }
          }
     }

     long long mst_wt=0;
 
     for(int i=1; i<V; i++){
         mst_wt+=graph[i][tree[i]];
        cout<<i<<" "<<tree[i]<<endl;
   }
   cout<<mst_wt<<endl;
}

int main(){
   int v;
   cin>>v;

   int graph[100][100];

   for(int i=0; i<v; i++){
       for(int j=0; j<v ;j++){
           cin>>graph[i][j];
       }
   }

   prims(graph,v);

}