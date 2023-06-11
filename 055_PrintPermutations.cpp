#include <bits/stdc++.h> 

void sol(string& s,int idx, vector<string>& ans,int n){
    if(idx == n){
        ans.push_back(s);
        return;
    }

    for(int i = idx; i<n;i++){
        swap(s[idx],s[i]);
        sol(s,idx+1,ans,n);
        swap(s[idx],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    int n = s.size();
    sol(s,0,ans,n);
    return ans;
}