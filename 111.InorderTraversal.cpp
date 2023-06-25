void sol(TreeNode *root,vector<int>& ans){
    if(!root) return;
    sol(root->left,ans);
    ans.push_back(root->data);
    sol(root->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    sol(root,ans);   
    return ans; 
}