int findCeil(BinaryTreeNode<int> *node, int x){
    if(!node) return -1;

    BinaryTreeNode<int> *cur = node;
    BinaryTreeNode<int> *ans = NULL;

    while(cur != NULL){
        if(cur->data == x) return x;
        if(cur->data > x){
            if(!ans || cur->data < ans->data) ans = cur;
        }
        if(cur->data < x) cur = cur->right;
        else cur = cur->left;
    }

    if(ans == NULL) return -1;
    return ans->data;
}