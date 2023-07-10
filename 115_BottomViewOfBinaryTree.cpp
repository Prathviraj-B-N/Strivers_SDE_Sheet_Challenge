#include <bits/stdc++.h> 
// T : O(n) S:O(n/2) 
vector<int> bottomView(BinaryTreeNode<int> *root){
    if(root == NULL) return {};
    vector<int> ans;
    map<int,int> mp;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i<n;i++){
            BinaryTreeNode<int> *cur = q.front().first;
            int idx = q.front().second;
            q.pop();
            mp[idx] = cur->data;
            if(cur->left != NULL) q.push({cur->left,idx-1});
            if(cur->right != NULL) q.push({cur->right,idx+1});
        }
    }
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
}
