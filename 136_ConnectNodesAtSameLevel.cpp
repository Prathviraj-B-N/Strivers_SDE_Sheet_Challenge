void connectNodes(BinaryTreeNode< int > *root) {

    if(root == NULL) return ;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();

        for(int i = 0;i<n;i++){
            auto cur = q.front();
            q.pop();
            

            if(cur->left) q.push(cur->left);
            if(cur->right)q.push(cur->right);
            
            if(i == n-1) break;
            cur->next = q.front();
        }
    }
    
}