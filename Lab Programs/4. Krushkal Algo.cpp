
/*
 Author : AMAN JAIN
 DATE: 03-07-2020

 PROGRAM ->  Krushkal Algo

O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply find-union algorithm.

*/



#include<bits/stdc++.h>
using namespace std;

#define MAX 20

int parent[MAX];

int find1(int u){
    if(parent[u]==u)
    return u;

    parent[u]=find1(parent[u]);
    return parent[u];
}


void union1(int u, int v){
    int x_rep=find1(u);
    int y_rep=find1(v);
    if(x_rep==y_rep)
    return;
    parent[u]=y_rep;

}

int main(){
    vector<pair<int,pair<int,int>>> Graph;
    int ver,edge;
    cin>>ver>>edge;
    
    for(int i=0 ; i<ver;i++){
        parent[i]=i;
    }

    for(int i=0 ; i<edge ; i++){
        int u,v,w;
        cin>>w>>u>>v;
        Graph.push_back({w,{u,v}});
    }

    long long mst=0;

    sort(Graph.begin(),Graph.end());
  
    vector<pair<int,pair<int,int>>> ::  iterator itr;
    for(itr=Graph.begin() ; itr!=Graph.end() ;itr++){
        int u= itr->second.first;
        int v= itr->second.second;

        int u_rep=find1(u);
        int v_rep=find1(v);

        if(u_rep!=v_rep){
            cout<<u<<" "<<v<<endl; 
            mst+=itr->first;
            union1(u_rep,v_rep);
        }
    }
  cout<<"Minimum Spanning Tree "<<mst<<endl;

}