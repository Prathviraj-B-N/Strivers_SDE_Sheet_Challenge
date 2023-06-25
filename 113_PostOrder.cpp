void sol(TreeNode *root,vector<int>& ans){
    if(!root) return;
    sol(root->left,ans);
    sol(root->right,ans);
    ans.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    sol(root,ans);   
    return ans;
}