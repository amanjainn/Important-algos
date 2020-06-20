

Algorithm : If a node is already visited and also exist in the current path then cycle exist



Using dfs






// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

void dfs(vector<int> adj[], int start, int path[], int visited[],bool &back_edge){
    visited[start]=1;
    path[start]=1;
    
    for(auto itr= adj[start].begin() ;itr!=adj[start].end();++itr){
        if(visited[*itr]==0){
           dfs(adj,*itr,path,visited,back_edge); 
        }
        
        if(visited[*itr]==1 && path[*itr]==1){
            back_edge=true;
            return;
        }
    }
    path[start]=0;
}

bool isCyclic(int V, vector<int> adj[]){
   bool back_edge=false;
   int visited[V]={0};
   int path[V]={0};
   for(int i=0  ;i<V; i++)
     dfs(adj,i,path,visited,back_edge);
   return back_edge;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends