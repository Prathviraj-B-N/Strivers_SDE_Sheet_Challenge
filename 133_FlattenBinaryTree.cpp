void sol(TreeNode<int> *node,TreeNode<int> *&ll){
    if(!node) return;
    sol(node->right,ll);
    sol(node->left,ll);
    node->right = ll;
    node->left = NULL;
    ll = node;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(!root) return root;
    TreeNode<int> *ll = NULL;
    sol(root,ll);
    return ll;
}