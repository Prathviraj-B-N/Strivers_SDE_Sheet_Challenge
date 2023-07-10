int sol(TreeNode<int> *root,int &diameter){
    if(root == NULL) return 0;
    int left = sol(root->left,diameter);
    int right = sol(root->right,diameter);
    diameter = max(diameter, left+right);
    return 1 + max(left,right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter = 0;
    if(!root) return 0;
    sol(root,diameter);
    return diameter;
}
