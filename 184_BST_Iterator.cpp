/*

    Your BSTIterator object will be instantiated and called as such:
    
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }

*/

class BSTiterator
{

    stack<pair<TreeNode<int>*,bool>> st; // <node,isExpanded>
    
    public:
    BSTiterator(TreeNode<int> *root)
    {
        st.push({root,false});
        while(st.top().second == false){
            auto cur = st.top();
            st.pop();
            if(cur.first->right) st.push({cur.first->right,false});
            st.push({cur.first,true});
            if(cur.first->left) st.push({cur.first->left,false});
        }
    }

    int next()
    {
        while(st.top().second == false){
            auto cur = st.top();
            st.pop();
            if(cur.first->right) st.push({cur.first->right,false});
            st.push({cur.first,true});
            if(cur.first->left) st.push({cur.first->left,false});
        }
        int ans = st.top().first->data;
        st.pop();
        return ans;
    }

    bool hasNext()
    {
        if(st.size() > 0) return true;
        return false;
    }
};