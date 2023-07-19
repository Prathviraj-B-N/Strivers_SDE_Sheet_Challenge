bool sol(BinaryTreeNode<int> *node,int lb,int ub){
    
    if(node->data > ub || node->data < lb) return false;
    
    if(node->left) {
        if(sol(node->left,lb,node->data) == false) return false;
    }
    
    if(node->right) {
        if(sol(node->right,node->data,ub) == false) return false; 
    }

    return true;

}

bool validateBST(BinaryTreeNode<int> *root) {
    if(root == NULL) return true;
    return sol(root,INT_MIN,INT_MAX);
}