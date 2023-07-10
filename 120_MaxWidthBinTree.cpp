#include <bits/stdc++.h> 

int getMaxWidth(TreeNode<int> *root)
{
    if(!root) return 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    int maxx = 0;

    while(!q.empty()){
        int n = q.size();
        maxx = max(maxx,n);
        for(int i=0;i<n;i++){
            TreeNode<int> *cur = q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }

    return maxx;
}