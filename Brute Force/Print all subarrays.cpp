#include <bits/stdc++.h> 
using namespace std;


#define REP(a,n) for(int i=a; i<n ;i++)
#define  pb(a)  push_back(a)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;



int main() {

    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin) ;
    freopen("output1.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n;
    cin>>n;

    int arr[n];

    for(int i=0 ;i<n;i++)
    cin>>arr[i];

    for(int i=0 ;i<n ;i++)
    {
        for(int j=i; j<=n ;j++)
        {
            for(int k=i ; k<j ;k++)
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }

}
