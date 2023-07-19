
bool isLeaf(BinaryTreeNode<int> *node){
    return (node->left == NULL && node->right==NULL);
}

void sol(BinaryTreeNode<int> *node){
    if(node == NULL) return;
    int childSum = 0;

    if(node->left )  childSum += node->left->data;
    if(node->right)  childSum += node->right->data;

    if(node->data < childSum) node->data = childSum;
    else{
        if(node->left) node->left->data = node->data;
        else if(node->right) node->right->data = node->data;
    }

    sol(node->left);
    sol(node->right);

    int total = 0;
    if(node->left) total += node->left->data;
    if(node->right) total += node->right->data;

    if(!isLeaf(node)) node->data = total;

}


void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL) return;
    sol(root);
}  