#include <bits/stdc++.h> 

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> ans = {-1,-1};

    BinaryTreeNode<int> *cur = root;

    // find sucessor
    while(cur){
        if(key < cur->data){
            ans.second = cur->data;
            cur = cur->left;
            continue;
        }
        cur = cur->right;
    }

    // find predecessor 
    cur = root;
    while(cur){
        if(key > cur->data){
            ans.first = cur->data;
            cur = cur->right;
            continue;
        }
        cur = cur->left;
    }

    return ans;
}
