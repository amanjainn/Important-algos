class Solution {
public:

TreeNode* trimBST(TreeNode* root, int L, int R) {
  if(root==NULL) return NULL;
    
  if(root->val<L)
  {
      root->left=NULL;//Left subtree will not have potential nodes-change it to NULL-So left traversal avoided 
      return trimBST(root->right,L,R);
  }
  else if(root->val>R)
  {
      root->right=NULL;//Right subtree will not have potential nodes-change it to NULL-So right traversal avoided
      return trimBST(root->left,L,R);
  }
  //In all other cases, we have to include the current node
  root->left=trimBST(root->left,L,R);
  root->right=trimBST(root->right,L,R);
  return root;
}
};