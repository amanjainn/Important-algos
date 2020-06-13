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


void bfs(int visited[], vector<int> V[],int &set_even,int &set_odd)
{
    visited[1]=1;
    queue<pair<int,int>> que;
    que.push(make_pair(1,0));
    int top,level;

    while(!que.empty())
    {
        pair<int,int> temp;
        temp = que.front();
        top=temp.first;
        level=temp.second;  
        que.pop();

        if(level%2==0)
        set_even++;
        else
        set_odd++;
           

        for(auto itr = V[top].begin() ; itr!=V[top].end() ;++itr)
        {
            if(visited[*itr]==0)
            {

                    visited[*itr]=1;
                    que.push(make_pair(*itr,level+1));
            
            }
        }
        
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
    n++;
    int edges;
    cin>>edges;

    vector<int> V[n];
    
    REP(0,edges){
        int x,y;
        cin>>x>>y;
        V[x].push_back(y);
    }

    int  set_even;
    int set_odd;


    int visited[n]={0};
    bfs(visited,V,set_even,set_odd);
    int total_edges= set_even * set_odd;
    cout<<total_edges-edges<<endl; 
}