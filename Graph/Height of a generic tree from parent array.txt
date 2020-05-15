#include <bits/stdc++.h> 
using namespace std;


#define REP(a,n) for(int i=a; i<n ;i++)
#define pb(a)  push_back(a)


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

void bfs(int start,int visited[], vector<int>v[],int &height)
{

    queue<pair<int,int>> qu;
    qu.push(make_pair(*(v[start].begin()),0));

    while(!qu.empty())
    {
        int top,level;
        pair<int,int> top1=qu.front();
        top=top1.first;
        level=top1.second;
        
        qu.pop();  

        for(auto itr= v[top].begin() ; itr!=v[top].end() ;++itr)
        {
            if(visited[*itr]==0)
            {
                visited[*itr]=1;
                qu.push(make_pair(*itr,level+1));
            }
        }
        height=max(level,height);
    }
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin) ;
    freopen("output1.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n;
    cin>>n;

    int parent[n];

    for(int i=0 ;i<n;i++)
    {
        cin>>parent[i];
    }

    vector<int> vect[2*n];
    for(int i=0 ; i<n ;i++)
    {
        if(parent[i]==-1)
        parent[i]=n+1;
        vect[parent[i]].push_back(i);
    }


    int visited[n]={0};
    int start=n+1;
    int height=0;
    bfs(start,visited,vect,height);

    cout<<height<<endl;
   
}
