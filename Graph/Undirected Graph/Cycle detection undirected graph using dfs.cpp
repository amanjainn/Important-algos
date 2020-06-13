/*

Name : Aman Jain
Date: 14-06-2020

*/

#include<bits/stdc++.h>
using namespace std;



int  hasCycle=0;


void CycleDetection(vector<int> Graph[],int visited[], int start, int parent){
    visited[start]=1;

    vector<int> :: iterator itr;
   for( itr= Graph[start].begin() ; itr!=Graph[start].end() ; itr++){
       if(visited[*itr]==1 && *itr!=parent)
        hasCycle=1;

       else if(visited[*itr]==0){
           CycleDetection(Graph,visited,*itr,start);
       }
   }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<int> Graph[2*V];
        for(int i=0 ; i<E; i++){
            int x,y;
            cin>>x>>y;
            Graph[x].push_back(y);
            Graph[y].push_back(x);
        }
        int visited[V]={0};
        for(int i=0  ;i<V ;i++)
        if(visited[i]==0)
        CycleDetection(Graph,visited,i,-1);

        cout<<hasCycle<<endl;
        hasCycle=0;
    }
}
