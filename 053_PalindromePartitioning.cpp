#include <bits/stdc++.h> 
bool isPal(string& s,int i,int j){

    while(i < j){
        if(s[i++] != s[j--]) return false;
    }
    return true;

}

void sol(int idx,string &s,vector<string> &temp,vector<vector<string>> &ans){
    if(idx == s.size()) {
        ans.push_back(temp);
        return;
    }

    for(int i = idx; i < s.size(); i++){
        if(isPal(s,idx,i)){
            temp.push_back(s.substr(idx,i-idx+1));
            sol(i+1,s,temp,ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> temp;
    sol(0,s,temp,ans);
    return ans;
}