#include <bits/stdc++.h> 

int sol(BinaryTreeNode<int> *root ){
    if(!root) return 0;

    int lh = sol(root->left);
    int rh = sol(root->right);

    if(lh == -1 || rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;

    return max(lh,rh) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(!root) return true;

    if(sol(root) == -1) return false;
    return true;
}