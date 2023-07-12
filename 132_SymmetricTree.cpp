// using recursion
bool sol(BinaryTreeNode<int> *root1,BinaryTreeNode<int> *root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->data != root2->data) return false;
    return sol(root1->left,root2->right) && sol(root1->right,root2->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root) return true;
    return sol(root->left,root->right);
}
// -------------------------------------------------------------------------
// using level order traversal
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root) return true;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        vector<int> temp;
        int n = q.size();
        for(int i = 0; i < n; i++){
            auto cur = q.front();
            q.pop();
            temp.push_back(cur->data);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        int i = 0;
        int j = temp.size()-1;

        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
    }
    return true;
}