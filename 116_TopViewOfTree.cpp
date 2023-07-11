#include <bits/stdc++.h> 

vector<int> getTopView(TreeNode<int> *root) {
    if(!root) return {};
    
    vector<int> ans;
    int minn = INT_MAX;
    int maxx = INT_MIN;
    queue<pair<TreeNode<int> *,int>> q;
    map<int,int> mp;
    
    q.push({root,0});
    
    while(!q.empty()){
        int n = q.size();
        
        for(int i = 0; i<n; i++){
            pair<TreeNode<int> *,int> cur = q.front();
            q.pop();
            TreeNode<int> *data = cur.first;
            int idx = cur.second;
            
            if(idx < minn ){
                mp[idx] = data->val;
                minn = idx;
            }
            if(idx > maxx){
                mp[idx] = data->val;
                maxx = idx;
            }
            
            if(data->left) q.push({data->left,idx-1});
            if(data->right) q.push({data->right,idx+1});
        }    
    }

    for(auto x:mp){
        ans.push_back(x.second);
    }
    
    return ans;
}