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


int  bfs (int n, int s, int d, vector<int> v[])
{
    int visited[n]={0};
    visited[s]=1;
    queue<pair<int,int>> que;
    que.push(make_pair(s,0));

    while(!que.empty())
    {
        pair<int,int> pr;
        pr=que.front();
        int top=pr.first;
        int level=pr.second;
        que.pop();
        if(top==d)
        return level;
        for(auto itr= v[top].begin() ; itr!=v[top].end() ; ++itr)
        {
            if(visited[*itr]==0)
            {
                que.push(make_pair(*itr,level+1));
                visited[*itr]=1;
            }
        }

    }
    return 0;
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

    int edge;
    cin>>edge;

    vector<int>v[2*n];

    for(int i=0 ; i<edge ; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int source,destination;
    cin>>source>>destination;
    int visited[n]={0};
    int min_edge=1000;
    int count=0;

    cout<<bfs(n,source,destination,v);




   
}