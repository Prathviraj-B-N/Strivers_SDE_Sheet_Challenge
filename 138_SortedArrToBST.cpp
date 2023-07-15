TreeNode<int> * sol(vector<int> &arr,int l,int r){
    if(l > r) {
        return NULL;
    }
    int mid = l+(r-l)/2;

    TreeNode<int> *node = new TreeNode<int>(arr[mid]);
    node->left = sol(arr,l,mid-1);
    node->right = sol(arr,mid+1,r);

    return node;
    
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return sol(arr,0,n-1);
}