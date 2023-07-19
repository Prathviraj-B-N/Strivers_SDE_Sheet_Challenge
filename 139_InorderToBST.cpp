TreeNode<int>* sol(vector<int> &preOrder,int &preidx,int ub){ //ub: upper bound
    if(preidx >= preOrder.size()) return NULL;
    if(preOrder[preidx] > ub) return NULL;

    TreeNode<int> *node = new TreeNode<int>(preOrder[preidx]);
    preidx++;

    node->left = sol(preOrder,preidx,node->data);
    node->right = sol(preOrder,preidx,ub);

    return node;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int preidx = 0;
    return sol(preOrder,preidx,INT_MAX);
}