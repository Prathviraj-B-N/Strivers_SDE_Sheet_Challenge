#include <bits/stdc++.h> 
void sol(vector<int>& arr,set<vector<int>>& ans,int idx,vector<int> temp, int n){
    if(idx == n){
        sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
    }

    temp.push_back(arr[idx]);
    sol(arr,ans,idx+1,temp,n);
    temp.pop_back();
    sol(arr,ans,idx+1,temp, n);
    return;

}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>> ans;
    sol(arr, ans, 0, {} ,n);

    vector<vector<int>> anss(ans.begin(),ans.end());
    sort(anss.begin(),anss.end());
    return anss;
}