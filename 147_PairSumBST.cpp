bool sol(BinaryTreeNode<int> *node,unordered_set<int> &st,int k){
    if(!node) return false;
    
    // if sum is less than root , it must be in left since only positive numbers are present.
    if(node->data > k) return sol(node->left,st,k);
    
    if(st.find(node->data)!=st.end()) return true;
    st.insert(k-node->data);
    
    bool a = sol(node->left,st,k);
    if(a) return true;
    
    bool b = sol(node->right,st,k);
    if(b) return true;
    
    return false;
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_set<int> st;
    return sol(root,st,k);
}