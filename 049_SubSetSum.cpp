#include <bits/stdc++.h> 
void  sol(vector<int> arr,vector<int> &ans,int idx,int sum, int n){
    if(idx == n){
        ans.push_back(sum);
        return;
    }

    sol(arr,ans,idx+1,sum+arr[idx],n);
    sol(arr,ans,idx+1,sum,n);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    sol(num,ans,0,0,num.size());
    sort(ans.begin(),ans.end());
    return ans;
}