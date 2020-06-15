/*
Date: 15-06-20
Name : Aman Jain
*/



#include<bits/stdc++.h>
using namespace std;


bool odd_cycle=false;
void dfs(vector<int> V[], int start, int parent, int color,int visited[]){
  visited[start]=color;
  //    Color : //  0: Not visited //  1: Visited and color 1 //  2: Visited and color 2
    vector<int> :: iterator itr;
    for(itr= V[start].begin() ; itr!=V[start].end() ;++itr){
        if(visited[*itr]==0){
            dfs(V,*itr,start,3-color,visited);
        }else if(visited[*itr]==color && *itr!=parent){
                odd_cycle=true;
        }
    }
}

int main(){
    int verti,edges;
    cin>>verti>>edges;

    vector<int> V[2*verti];
    for(int i=0; i<edges; i++){
       int x,y;
       cin>>x>>y;
       V[x].push_back(y);
       V[y].push_back(x);
    }

    int visited[verti]={0};
    dfs(V,1,-1,1,visited);

    if(odd_cycle)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;

}

