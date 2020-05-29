#include <bits/stdc++.h>
using namespace std;

#define REP(a, n) for (int i = a; i < n; i++)
#define pb(a) push_back(a)

typedef long long ll;
typedef long l;
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef map<int,int> Map;

long long  arr[100005];

int main()
{

#ifndef ONLINE_JUDGE
freopen("input1.txt", "r", stdin);
freopen("output1.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


double d=1;
double denom  =0;
int count=0;
double i=0;
while (d>1-0.5){
  
  denom = (365-i)/365;
  d*=denom;
  i++;

  count++; 
}

cout<<count<<endl;
}


 
