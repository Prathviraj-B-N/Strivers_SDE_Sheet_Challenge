#include <bits/stdc++.h> 

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    if(!root)
      return {};

    bool ltor = true;
    deque<BinaryTreeNode<int> *> q;
    q.push_back(root);
    vector<int> ans;
    while(!q.empty()){
        int n = q.size();

        for(int i = 0; i < n; i++){
            if(ltor){
                auto cur = q.front();
                ans.push_back(cur->data);
                if(cur->left) q.push_back(cur->left);
                if(cur->right) q.push_back(cur->right);
                q.pop_front();
            }else{
                auto cur = q.back();
                ans.push_back(cur->data);
                if(cur->right) q.push_front(cur->right);
                if(cur->left) q.push_front(cur->left);
                q.pop_back();
            }
            
        }
            ltor = ltor?false:true;
    }
    return ans;

}
