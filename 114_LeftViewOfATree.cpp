void sol(TreeNode<int> *root,vector<int>& ans,int idx,unordered_set<int>& st){
    if(!root) return;
    if (st.find(idx) == st.end()) {
      ans.push_back(root->data);
      st.insert(idx);
    }

    sol(root->left,ans, idx+1,st);
    sol(root->right,ans, idx+1,st);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    unordered_set<int> st;
    vector<int> ans;
    sol(root,ans,0,st);
    return ans;
}