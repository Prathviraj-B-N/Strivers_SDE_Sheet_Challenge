int floorInBST(TreeNode<int> * root, int X)
{
    TreeNode<int>* cur = root;
    TreeNode<int>* ans = NULL;

    while(cur){
        if(cur->val <= X){
            if(!ans || cur->val > ans->val) ans = cur;
        }
        if(cur->val > X){
            cur = cur->left;
        }
        else cur = cur->right;
    }

    if(!ans) return -1;
    return ans->val;
}