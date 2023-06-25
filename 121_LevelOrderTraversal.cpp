vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(!root) return {};
    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int> *cur = q.front();
        if(!cur) {q.pop();continue;}
        ans.push_back(cur->val);
        q.pop();
        q.push(cur->left);
        q.push(cur->right);
    }
    return ans;

}