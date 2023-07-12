#include <bits/stdc++.h> 
#define ll long long

ll sol(TreeNode<int> *node,ll &sum){
    if(!node) return 0;
    if(!node->left && !node->right){
        sum = max(sum,(ll)node->val);
        return node->val;
    }

    ll a = sol(node->left,sum);
    ll b = sol(node->right,sum);
    sum = max(sum, a+b+(ll)node->val);
    return node->val + max(a,b);
}

ll int findMaxSumPath(TreeNode<int> *root)
{
    if(!root || !root->left || !root->right) return -1;

    ll sum = 0;
    sol(root,sum);

    return sum;
    
}