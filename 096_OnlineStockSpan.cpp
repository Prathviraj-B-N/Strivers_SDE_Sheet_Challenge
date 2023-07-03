#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    stack<int> st;

    int n = price.size();
    vector<int> ans(n);

    for(int i = 0; i < n;i++){
        while(!st.empty() && price[st.top()] <= price[i]) st.pop();
        if(!st.empty()) ans[i] = i - st.top();
        else ans[i] = i+1;
        st.push(i);
    }
    return ans;
}

/*
    previous greater algo
    push if cur is less than st.top because if ele was greater than all prev ele would be not useful
*/