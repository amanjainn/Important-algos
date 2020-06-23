/*
Name - Aman Jain
Date - 23-06-2020
*/


#include<bits/stdc++.h>
using namespace std;

int main (){
    int verti,edges;
    cin>>verti>>edges;

    int visi[verti +1]={0};

    vector<pair<int,int>> gr[verti+1]; //1 based vertices
    for(int i=0; i<edges ;i++){
        int x,y,w;  //x,y edge from x to y having weight w
        cin>>x>>y>>w;
        gr[x].push_back({y,w});
        gr[y].push_back({x,w});
    }
    // Min Heap
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;

   Q.push({0,1});
//   weight,node

   long long int mst=0;
    while(!Q.empty()){
        pair<int,int> best= Q.top();
        Q.pop();

        int weight=best.first;
        int to= best.second;

        // Not an active edge
        if(visi[to]) continue;

        mst+=weight;
        visi[to]=1;

        // to vertex is visited
        for(auto x : gr[to]){
            if(visi[x.first]==0){
                //  x.first is not visited
                Q.push({x.second,x.first});
            }
        }
    }
    cout<<mst<<endl;
   


}