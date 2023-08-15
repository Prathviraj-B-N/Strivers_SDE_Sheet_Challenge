vector<vector<int>> powerset(vector<int> nums){
    
    // len(powerset) == 2^n
    int n = (1<<nums.size());
    vector<vector<int>> ans;
    
    // ith combination
    for(int i = 0 ; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < nums.size(); j++){
            if(i & (1<<j)) temp.push_back(nums[j]); // check if jth bit of i == 1 ?
        }
        ans.push_back(temp);
    }
    
    return ans;

}