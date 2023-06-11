void sol(int idx,int sum,vector<int> temp,vector<int>& arr,vector<vector<int>>& ans,int k,int n){
    if(idx == n) {
        if(sum == k){
            ans.push_back(temp);
        }
        return;
    }

    temp.push_back(arr[idx]);
    sum += arr[idx];
    sol(idx+1,sum,temp,arr,ans, k, n);

    temp.pop_back();
    sum -= arr[idx];
    sol(idx+1,sum,temp,arr,ans, k, n);

    return;

}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    sol(0,0,{},arr,ans, k, n);
    return ans;
}