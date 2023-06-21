#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    
    stack<int> st;
    vector<int> ans(n,-1);

    for(int i=n-1; i >= 0; i--){
        while(st.size() && st.top() <= arr[i]) st.pop(); //if st.top is less than cur, 
        if(st.size()) ans[i] = st.top();   //then there is no way any arr[i] < cur ,will have it as its next greater 
        st.push(arr[i]);
    }

    return ans;

}