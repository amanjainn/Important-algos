#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <ext/pb_ds/detail/standard_policies.hpp>
 
//using namespace __gnu_pbds; 
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define eb emplace_back
#define sortA(a,n) sort(a,a+n)
#define sortRA(a,n) sort(a,a+n,greater<int>())
#define sortV(v)  sort(v.begin(),v.end())
#define sortRV(v)  sort(v.begin(),v.end(),greater<int>())
#define minHeap priority_queue<int,vector<int>,greater<int>>
#define MAX(a,b,c) max(a,max(b,c))
typedef pair<int,int> pi;
 
// typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> pbds; 
const char nl ='\n';
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
const int N=1e6+1; 
int dx[]={-1,1,0,0,1,-1,-1,1};
int dy[]={0,0,-1,1,1,-1,1,-1};
 
 
ll div_ceil(ll numerator, ll denominator)
{
        std::lldiv_t res = std::div(numerator, denominator);
        return res.rem ?(res.quot + 1) : res.quot;
}
 
void IO() {
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
}
 
// ============= CODE =============
 

struct SegmentTreeNode
{
       int prefixMaxSum, suffixMaxSum, maxSum, sum;

       void assignLeaf(int value)
       {
             prefixMaxSum=suffixMaxSum=maxSum=sum=value;      
       }

       void merge(SegmentTreeNode &left, SegmentTreeNode &right)
       {
            sum=left.sum+ right.sum;
            prefixMaxSum=max(left.prefixMaxSum,left.sum+right.prefixMaxSum);
            suffixMaxSum=max(right.suffixMaxSum,right.sum+left.suffixMaxSum);
           maxSum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxSum, max(right.maxSum, left.suffixMaxSum + right.prefixMaxSum))));
       }
       
       int getValue()
       {
           return maxSum;
       }

};


template<class T, class V>
class SegmentTree {
	SegmentTreeNode* nodes;
	int N;
	
public:
	SegmentTree(T arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	V getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	
	void update(int index, T value) {
		update(1, 0, N-1, index, value);
	}
	
private:	
	void buildTree(T arr[], int stIndex, int lo, int hi)
     {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
	
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) 
    {
		if (left == lo && right == hi)
			return nodes[stIndex];
			
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);
			
		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}
	
	int getSegmentTreeSize(int N)
     {
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}
	
	void update(int stIndex, int lo, int hi, int index, T value)
     {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(value);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		if (index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};


void decode()
{   
        int N,A[50000],M,x,y;
        cin>>N;

        for(int i=0; i<N ;i++)
        {
            cin>>A[i];
        }      
        SegmentTree<int,int> st(A,N);
        cin>>M;
        for(int i=0; i<M; ++i)
        {
                cin>>x>>y;
                cout<<st.getValue(x-1,y-1)<<endl;
        }
}

int32_t main()
{
      //  IO(); 
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int T=1;  
      //  cin>>T;
        while(T--)  
        {
                decode(); 
        }
        return 0;
} 
