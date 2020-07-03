
/*
 Author : AMAN JAIN
 DATE: 03-07-2020

 PROGRAM ->  DFS

Time Complexity of the below program is O(V+E) using adjacency list. 

*/


#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> list[], int visited[], int start){
    visited[start]=1;
    cout<<start<<" ";

    vector<int> :: iterator itr;

    for(itr=list[start].begin(); itr!=list[start].end() ;itr++){
        if(!visited[*itr])
          dfs(list,visited,*itr);
    }
}



int main(){
    int v,e;
    cin>>v>>e;
    // Directed graph
    vector<int> list[v]; //Adjacency list;
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        list[x].push_back(y);
    }

    int visited[v]={0};
    for(int i=0 ; i<v; i++){
        if(!visited[i])
        dfs(list,visited,i);
    }

}