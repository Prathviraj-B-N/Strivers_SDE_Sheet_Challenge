// O(2^n) recursion
int longestIncreasingSubsequence(int arr[], int n,int cur=0,int prev=-1)
{
    if(cur == n) return 0;

    int ans = longestIncreasingSubsequence(arr,n,cur+1,prev);
    
    if(arr[cur]>arr[prev]){
        ans = max(ans,1+longestIncreasingSubsequence(arr,n,cur+1,cur));
    }
    return ans;
}

// T O(n^2) S O(n^2) memoisation
int sol(int arr[], int n,int cur,int prev,vector<vector<int>> &dp){
    if(cur == n) return 0;
    if(dp[cur][prev+1] != -1) return dp[cur][prev+1];
    int ans = sol(arr,n,cur+1,prev,dp);
    
    if(arr[cur]>arr[prev]){
        ans = max(ans,1+sol(arr,n,cur+1,cur,dp));
    }
    dp[cur][prev+1] = ans;
    return ans;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return sol(arr,n,0,-1,dp);
}

// T O(n^2) S O(n) dp 
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dpcur(n+1,0);
    vector<int> dpnxt(n+1,0);

    for(int cur = n-1; cur >= 0; cur--){
        for(int prev = cur-1; prev >= -1;prev--){
            int ans = dpnxt[prev+1];
            if(prev == -1 || arr[cur] > arr[prev]) ans = max(ans,1+dpnxt[cur+1]);
            dpcur[prev+1] = ans;
        }
        dpnxt = dpcur;
    }

    return dpnxt[0];
}