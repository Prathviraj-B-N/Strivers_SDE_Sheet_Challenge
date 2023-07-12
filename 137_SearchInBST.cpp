bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp = root;

    while(temp != NULL){
        if(temp->data == x) return true;
        
        if(x < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return false;
}