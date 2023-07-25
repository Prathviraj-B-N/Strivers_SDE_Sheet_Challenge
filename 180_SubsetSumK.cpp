// -------------------------- Recursion -------------------------------//
// T O(2^n) S O(n)
bool sol(vector<int> &arr,int idx,int k){
    if(k == 0) return true;
    if(k < 0) return false;
    if(idx < 0) return false;
    if(sol(arr,idx-1,k-arr[idx]) == true) return true;
    if(sol(arr,idx-1,k) == true) return true;

    return false;

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return sol(arr,n-1,k);
}

// -------------------------- DP -------------------------------//
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));

    for(int i = 0; i < n;i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    
    for(int idx = 0; idx < n;idx++){
        for(int wt = 1; wt <= k; wt++){
            if((idx-1 >= 0 && wt-arr[idx] >=0 && dp[idx-1][wt-arr[idx]] == true) || (idx-1>=0 && dp[idx-1][wt] == true)){
                dp[idx][wt] = true;
            }
        }
    }

    return dp[n-1][k];
}

// -------------------------- Space Optimization -------------------------------//
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,false);
    vector<bool> cur(k+1,false);

    prev[0] = true;
    cur[0] = true;
    prev[arr[0]] = true;

    for(int idx = 1; idx < n;idx++){
        for(int wt = 1; wt <= k; wt++){
            if((arr[idx] <= wt && prev[wt-arr[idx]]) ||  prev[wt]){
                cur[wt] = true;
            }
        }
        prev = cur;
    }
    return prev[k];
}
