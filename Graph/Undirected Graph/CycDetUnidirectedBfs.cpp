#include<bits/stdc++.h>
using namespace std;

bool hascycle=false;

int visited[100]={0};
void bfsCycleDetection(vector<int> graph[],int v,int src){
    int parent[v]={0};
    visited[src]=1;
    parent[src]=-1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int s: graph[curr]){
            if(!visited[s]){
                parent[s]=src;
                visited[s]=1;
                q.push(s);
            }else if(visited[s] && parent[s]!=curr){
                        hascycle=true;
                        return;
            }
        }
    }

}


int main(){
    int v,e;
    cin>>v>>e;
    vector<int> graph[v];
    for(int i=0;i<e; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    for(int i=0; i<v; i++){
        if(visited[i]==0)
             bfsCycleDetection(graph,v,i);
    }
    cout<<(hascycle ?"Yes": "No")<<endl;
}
