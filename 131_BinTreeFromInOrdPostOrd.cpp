int find(vector<int> &inOrder,int ele){
     for(int i = 0; i < inOrder.size();i++){
          if(inOrder[i] == ele) return i;
     }
     return -1;
}

TreeNode<int>* sol(vector<int> &postOrder,vector<int> &inOrder,int l,int r,int &postidx){
     if(l > r) return NULL;
      TreeNode<int> *node = new TreeNode<int>(postOrder[postidx]);
     int f = find(inOrder,postOrder[postidx]);
     postidx--;
     node->right = sol(postOrder,inOrder,f+1,r,postidx);
     node->left  = sol(postOrder,inOrder,l,f-1,postidx);
     return node;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     int postidx = postOrder.size()-1;
	return sol(postOrder,inOrder,0,postidx,postidx);
}