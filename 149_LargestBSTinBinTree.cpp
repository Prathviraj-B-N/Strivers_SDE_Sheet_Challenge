// {minEleOfSubtree, maxEleOfSubtree, maxSize}

vector<int> sol(TreeNode<int> *node){
    if(!node) return {INT_MAX,INT_MIN,0};
    
    vector<int> l = sol(node->left);
    vector<int> r = sol(node->right);

    if(node->data > l[1] && node->data < r[0]){
        return {min(l[0],node->data),max(node->data,r[1]),l[2]+r[2]+1};
    }

    return {INT_MIN,INT_MAX,max(l[2],r[2])};

}

int largestBST(TreeNode<int>* root) 
{
    return sol(root)[2];
}