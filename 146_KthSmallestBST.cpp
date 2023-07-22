// traverse left root right. and kth node will be kth largest
int sol(TreeNode<int>* node,int k,int &count){
    if(!node) return -1;
    int a = sol(node->left,k,count);
    if(a != -1) return a;
    ++count;
    if(count == k) return node->data;
    int b = sol(node->right,k,count);
    if(b!=-1) return b;
    return -1;
    
}

int kthSmallest(TreeNode<int> *root, int k)
{
	int count = 0;
    return sol(root,k,count);
}