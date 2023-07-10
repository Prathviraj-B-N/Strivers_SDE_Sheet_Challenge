#include <bits/stdc++.h> 

bool sol(TreeNode<int> *root,vector<int> &ans,int x){
	if(!root) return false;
	ans.push_back(root->data);
	if(sol(root->left,ans,x)) return true;
	if(sol(root->right,ans,x)) return true;
	if(root->data == x) return true;
	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> ans;
	sol(root,ans,x);
	return ans;
}
