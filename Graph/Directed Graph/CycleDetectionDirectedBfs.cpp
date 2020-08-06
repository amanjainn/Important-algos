#include<bits/stdc++.h>
using namespace std;

bool hascycle=false;

void cycleDetectionBfs(vector<int> graph[],int v){
    queue<int> q;
    int indegree[v]={0};
    for(int i=0 ; i<v; i++){
        for(auto itr=graph[i].begin() ;itr!=graph[i].end() ;itr++){
            indegree[*itr]++;
        }
    }
    for(int i=0 ; i<v; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
        int count=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto itr=graph[curr].begin() ;itr!=graph[curr].end() ;itr++){
            indegree[*itr]--;
            if(indegree[*itr]==0){
                q.push(*itr);
            }
        }
        count++;
    }
    if(count!=v){
        hascycle=true;
    }

}



int main(){
    int v,e;
    cin>>v>>e;
    vector<int> graph[v];
    for(int i=0; i<v; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    cycleDetectionBfs(graph,v);
    cout<<(hascycle?"Yes": "No");
}
