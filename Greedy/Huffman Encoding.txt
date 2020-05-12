#include<bits/stdc++.h>
using namespace std;


#define MAX_SIZE 100

class HuffmanTreeNode {

public:
     char data;
     int freq;

     HuffmanTreeNode * left;
     HuffmanTreeNode * right;

     HuffmanTreeNode(char c,int frequency)
     {
         data=c;
         freq=frequency;
         left=right=NULL;
     }
};

class Compare{
public:
    bool operator()(HuffmanTreeNode *a,HuffmanTreeNode*b)
    {
        return a->freq > b->freq;
    }
};


HuffmanTreeNode * generateTree(priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>, Compare> pq)
{
    while(pq.size()!=1)
    {

        HuffmanTreeNode *left=pq.top();
        pq.pop();

        HuffmanTreeNode *right=pq.top();
        pq.pop();

        HuffmanTreeNode *node =new HuffmanTreeNode('$',left->freq+right->freq);
        node->left=left;
        node->right=right;

        pq.push(node);

    }
    return pq.top();

}


void printCode(HuffmanTreeNode *root,int arr[], int top)
{

    if(root->left){
        arr[top]=0;
        printCode(root->left,arr,top+1);
    }

    if(root->right)
    {
        arr[top]=1;
        printCode(root->right,arr,top+1);
    }


    if(!root->left && !root->right){
        cout<<root->data<<" ";
        for(int i=0 ; i<top ;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }
}




void HuffmanCode(char data[],int freq[],int siz)
{
    priority_queue<HuffmanTreeNode *, vector<HuffmanTreeNode*>,Compare> pq;


    for(int i= 0; i<siz ; i++)
    {
        HuffmanTreeNode * newNode=  new HuffmanTreeNode(data[i],freq[i]);
        pq.push(newNode);

    }



    HuffmanTreeNode*root= generateTree(pq);

    int arr[MAX_SIZE],top=0;
    printCode(root,arr,top);
}






int main()
{

    char data[]={'a','b','c','d','e','f'};
    int freq[]= { 5,9,12,13,16,45};
    int siz=sizeof(data)/sizeof(data[0]);

    HuffmanCode(data,freq,siz);
    return 0;
}
