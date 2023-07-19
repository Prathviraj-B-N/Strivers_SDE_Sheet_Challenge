TreeNode<int>* sol(TreeNode<int>* node,TreeNode<int> *&p,TreeNode<int> *&q){
    if(node == NULL) return NULL;
    if(p->data > node->data && q->data > node->data) return sol(node->right,p,q);
    if(p->data < node->data && q->data < node->data) return sol(node->left,p,q);
    // if p is less and q is more etc , then just return node because it is splitting here right... no common path b/w p and q anymore 
    return node;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	return sol(root,P,Q);
}
