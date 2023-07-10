#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    if(root==NULL) return {};
    stack<pair<BinaryTreeNode<int> *,int>> st;
    // 1-> put it to preorder q
    // 2-> inorder
    // 3-> post order   

    vector<int> inorder;    
    vector<int> preorder;
    vector<int> postorder;


    st.push({root,1});

    while(!st.empty()){
        auto cur = st.top();
        st.pop();
        if(cur.second == 1){
                preorder.push_back(cur.first->data);
                st.push({cur.first,2});
                if(cur.first->left)
                  st.push({cur.first->left, 1});
        }
        else if(cur.second == 2){
                inorder.push_back(cur.first->data);
                st.push({cur.first,3});
                if(cur.first->right)
                  st.push({cur.first->right, 1});
        }
        else if(cur.second == 3){
                postorder.push_back(cur.first->data);
        }
    }
    return {inorder,preorder,postorder};
}