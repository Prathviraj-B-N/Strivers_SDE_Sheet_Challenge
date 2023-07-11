#include <bits/stdc++.h> 

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if(!root) return {};
    
    map<int,vector<int>> mp;
    vector<int> ans;
    queue<pair<TreeNode<int> *,int>> q;
    
    q.push({root,0});

    while(!q.empty()){
        int n = q.size();

        for(int i = 0; i < n; i++){
            auto cur = q.front();
            int idx = cur.second;
            mp[idx].push_back(cur.first->data);
            if(cur.first->left) q.push({cur.first->left,idx-1});
            if(cur.first->right) q.push({cur.first->right,idx+1});
            q.pop();
        }
    }

    for(auto x:mp){
        for(auto ele:x.second) ans.push_back(ele);
    }
    return ans;
}