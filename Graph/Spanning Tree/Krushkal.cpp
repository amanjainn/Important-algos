/*
Name - Aman Jain
Date - 24-06-2020
*/

#include<bits/stdc++.h>
using namespace std;

struct DisjoinSets
{
    int *parent,*rank;
    int n;
    DisjoinSets(int n)
    {
        this->n=n;
        parent=new int[n+1];
        rank= new int[n+1];
        for(int i=0 ; i<=n ; i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int u){
        if(parent[u]==u)
         return u;
         parent[u]=find(parent[u]);
         return parent[u];
    }
    void unite(int u, int v){
        int u_rep= find(u);
        int v_rep=find(v);
    
        if(u_rep==v_rep)
        return;
            
        if(rank[u_rep]>rank[v_rep])
            parent[v_rep]=u_rep;

        else if(rank[u_rep]<rank[v_rep])
            parent[u_rep]=v_rep;
         else{
             rank[v_rep]++;
             parent[u_rep]=v_rep;
         }    
    }
    
};

int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,pair<int,int>>> Graph;

    for(int i =0 ;  i<e ;i++){
        int x,y,w;    
        cin>>x>>y>>w;
        Graph.push_back({w,{x,y}});
    }

    long long mst_wt=0;

    sort(Graph.begin(),Graph.end());

    DisjoinSets ds(v);

    for(auto itr= Graph.begin() ;itr!=Graph.end() ;++itr){
        int u= itr->second.first;
        int v= itr->second.second;

        int u_rep=ds.find(u);
        int v_rep=ds.find(v);
        if(u_rep!=v_rep){
            cout<<u<<" "<<v<<endl;
            mst_wt+=itr->first;
            ds.unite(u_rep,v_rep);
        }
    }
    

    cout<<"Minimium Weight "<<mst_wt<<endl;
  

}
