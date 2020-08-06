#include<bits/stdc++.h>
using namespace std;

void shortestPath(vector<int> Graph[], int src, int des ,int v){
    int visited[v]={0};
    int distance[v]={0};
    queue<int> qu;
    qu.push(src);
    distance[src]=0;
    visited[src]=1;
    bool found=false;
    while(!qu.empty()){
        int curr=qu.front();
        qu.pop();
        for(auto itr=Graph[curr].begin() ;itr!=Graph[curr].end() ;itr++){
            if(!visited[*itr]){
               distance[*itr]=distance[curr]+1;
               qu.push(*itr);
               visited[*itr]=1;
            }

        }
    }
    cout<<distance[des]<<endl;
}


int main(){
    int v,e;
    cin >> v>> e;
    vector<int> Graph[v];
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    int src,des;
    cin>>src>>des;
    shortestPath(Graph,src,des,v);
}
