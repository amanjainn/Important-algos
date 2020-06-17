/*
Date: 17-06-20
Name : Aman Jain
*/

#include<bits/stdc++.h>
using namespace std;

void topologicalSort(vector<int> V[],list<int> &order,int visited[],int start){
    visited[start]=1;
    
    for(auto itr= V[start].begin(); itr!=V[start].end() ;itr++){
        if(visited[*itr]==0){
            topologicalSort(V,order,visited,*itr);
        }
    }
    order.push_front(start);
}




int main(){
    int t;
    cin>>t;
    while(t--){
        int vertices,edges;
        cin>>edges>>vertices;
        vector<int> V[vertices];
  
        for(int i=0 ; i<edges ; i++){
            int x,y;
            cin>>x>>y;
            V[x].push_back(y);
        }
        int visited[vertices]={0};
        list<int> order;


        for(int i=0; i<vertices ;i++){
            if(visited[i]==0)
         topologicalSort(V,order,visited,i);
        }
        // Print the order

        for(auto itr= order.begin() ;itr!=order.end();itr++ ){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }

}


