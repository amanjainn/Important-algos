
/*
Date: 21-06-20
Name : Aman Jain
*/

#include<bits/stdc++.h>
using namespace std;


void dfs( int start, int visited[], vector<int> &order, vector<int> Graph []){
    visited[start]=1;
    for(auto itr = Graph[start].begin() ;itr!=Graph[start].end() ;itr++){
        if(!visited[*itr])
        dfs(*itr,visited,order,Graph);
    }
    order.push_back(start);
}

void rev_dfs(int start, vector<int>rev_Graph[],int visited[],int comp[], int comp_num){
    visited[start]=1;
    comp[start]=comp_num;
    
      for(auto itr = rev_Graph[start].begin() ;itr!=rev_Graph[start].end() ;itr++){
        if(!visited[*itr])
        rev_dfs(*itr,rev_Graph,visited,comp,comp_num);
    }
}

int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    
    vector<int> Graph[vertices],rev_Graph[vertices];
    
    for(int i=0 ; i<edges; i++){
        int x,y;
        cin>>x>>y;
        Graph[x].push_back(y);
        rev_Graph[y].push_back(x);
    }
    
    
    vector<int> order;
    int visited[vertices]={0};
    
    for(int i=0  ;i<vertices ; i++){
        if(!visited[i])
        dfs(i,visited,order,Graph);
    }
    
    memset(visited,0,sizeof(visited));
    int comp[vertices]={0};
    int comp_num=1;
    for(int i=vertices-1 ; i>=0 ; i-- ){
        if(visited[order[i]]==0){
        rev_dfs(order[i],rev_Graph,visited,comp,comp_num);
        comp_num++;
        }
    }
    
    for(int i=0 ; i<vertices ;i++){
        cout<<i<<"-- "<<comp[i]<<endl;
    }
    
}