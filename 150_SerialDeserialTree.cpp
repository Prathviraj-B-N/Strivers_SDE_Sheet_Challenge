#include<bits/stdc++.h>

string serializeTree(TreeNode<int> *root)
{
    if(!root) return "";

    queue<TreeNode<int>*> q;
    q.push(root);

    string s = "";
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        if(cur == NULL) s.append("#,");
        else s.append(to_string(cur->data)+',');

        if(cur != NULL){
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    if(serialized.size() == 0) return NULL;

    stringstream sstr(serialized);
    string s;
    getline(sstr,s,',');

    TreeNode<int>* root = new TreeNode<int>(stoi(s));
    
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        string left,right;

        getline(sstr,left, ',');
        getline(sstr,right,',');

        if(left == "#") cur->left = NULL;
        else{
            TreeNode<int> *leftNode = new TreeNode<int>(stoi(left));
            cur->left = leftNode;
            q.push(leftNode);
        }

        if(right == "#") cur->right = NULL;
        else{
            TreeNode<int> *rightNode = new TreeNode<int>(stoi(right));
            cur->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}