#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=n-1; i >= 0; i--){
        while(st.size() && st.top() >= arr[i]) st.pop();
        if(st.size()) ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}