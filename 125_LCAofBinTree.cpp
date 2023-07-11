#include <bits/stdc++.h> 

int sol(TreeNode<int> *node,int x, int y){
    if(!node) return -1;
    if(node->data == x || node->data == y) return node->data;
    int l = sol(node->left,x,y);
    int r = sol(node->right,x,y);

    if(l != -1 && r != -1) return node->data;

    if(l == -1) return r;
    return l;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(!root) return -1;
    return sol(root,x,y);
}