void sol(TreeNode *root,vector<int>& ans){
    if(!root) return;
    ans.push_back(root->data);
    sol(root->left,ans);
    sol(root->right,ans);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    sol(root,ans);   
    return ans;
}