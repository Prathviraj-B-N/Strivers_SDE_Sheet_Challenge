int find(vector<int> inorder,int ele,int l,int r){
    for(int i=l;i<=r;i++){
        if(inorder[i]==ele) return i;
    }
}

TreeNode<int>* sol(vector<int> &inorder,vector<int> &preorder,int l,int r,int &pidx){
    if(l > r) return NULL;

    TreeNode<int> *node = new TreeNode<int>(preorder[pidx]);
    int f = find(inorder,preorder[pidx],l,r);

    pidx++;
    node->left  = sol(inorder,preorder,l,f-1,pidx);
    node->right = sol(inorder,preorder,f+1,r,pidx);

    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int pidx = 0;
    return sol(inorder,preorder,0,preorder.size()-1,pidx);
}