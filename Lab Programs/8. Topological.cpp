/*
 Author : AMAN JAIN
 DATE: 03-07-2020

 PROGRAM ->  Topological sort

 Time Complexity: O(V+E).
 Auxillary Space: O(V).

Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.

Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
Step 5: Repeat Step 3 until the queue is empty.



*/

#include<bits/stdc++.h>
using namespace std;

void topologicalSort(vector<int> Graph[],int n){
    int in_deg[n]={0};

// FIll the ingrees of all vertices
    for(int i=0 ; i<n ; i++){
        vector<int> :: iterator itr;

        for(itr=Graph[i].begin() ;itr!=Graph[i].end() ;itr++){
            in_deg[*itr]++;
        }
    }
     //Push all vertices with zero indegree
    queue<int> q;
    for(int i=0; i<n ; i++){
        if(in_deg[i]==0)
            q.push(i);
    }

    // initialize count of visited vertices
    int count=0;

    vector<int> top_order;

    // Pop each element and check if indgree of adjacent becomes 0
   
    while(!q.empty()){
           int u=q.front();
           q.pop();
           top_order.push_back(u);
           vector<int> :: iterator itr;
           for(itr=Graph[u].begin() ;itr!=Graph[u].end() ;itr++){
               in_deg[*itr]--;
               if(!in_deg[*itr])
               q.push(*itr);
           }
           count++; 
    }
    if(count!=n){
        cout<<"Graph is not DAG"<<endl;
        return ;
    }
    for(int  i=0; i<top_order.size() ;i++){
        cout<<top_order[i]<<" ";
    }
    cout<<endl;

}


int main(){
    int v,e;
    cin>>v>>e;
    vector<int> Graph[v];
    for(int i=0 ; i<e; i++){
        int x,y;
        cin>>x>>y;
        Graph[x].push_back(y);
    }  
   topologicalSort(Graph,v);
}
