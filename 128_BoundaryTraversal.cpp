#include <bits/stdc++.h> 

void solLeft(TreeNode<int> *node,vector<int> &ans){
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL) return;
    ans.push_back(node->data);
    if(node->left)solLeft(node->left,ans);
    else solLeft(node->right,ans);
}

void solBottom(TreeNode<int> *node,vector<int> &ans){
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL){
        ans.push_back(node->data);
        return;
    }
    solBottom(node->left,ans);
    solBottom(node->right,ans);
}

void solRight(TreeNode<int> *node,vector<int> &ans){
    if(node == NULL) return;
    if(node->left == NULL && node->right == NULL) return;
    if(node->right) solRight(node->right,ans);
    else solRight(node->left,ans);
    ans.push_back(node->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){

    if(!root) return {};

    vector<int> ans;
    ans.push_back(root->data);

    solLeft(root->left,ans);
    solBottom(root->left,ans);
    solBottom(root->right,ans);
    solRight(root->right,ans);

    return ans;
}