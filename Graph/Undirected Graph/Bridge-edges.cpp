#include<bits/stdc++.h>
using namespace std;

void bridgeEdge(vector<int> graph[],int parent[],int disc[],int low[],int visited[],int src){
    static int time=0;
    visited[src]=1;
    disc[src]=low[src]=++time;
    for(int x: graph[src]){
        if(!visited[x]){
            parent[x]=src;
            bridgeEdge(graph,parent,disc,low,visited,x);
            low[src]=min(low[src],low[x]);
            if(low[x]>disc[src]){
                cout<<x<<" "<<src<<endl;
            }

        }else if(x!=parent[src]){
            low[src]=min(low[src],disc[x]);
        }
    }

}


int main(){
    int v,e;
    cin>>v>>e;
    vector<int> graph[v];
    for(int i=0 ; i<e; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int parent[v],disc[v]={0},low[v]={0},visited[v]={0};
    parent[0]=-1;
    for(int i=0; i<v ;i++){
        if(!visited[i])
            bridgeEdge(graph,parent,disc,low,visited,i);
    }
}
