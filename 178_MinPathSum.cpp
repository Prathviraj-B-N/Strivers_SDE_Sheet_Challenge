// --------------------------   Recursion   -------------------------------//

int sol(vector<vector<int>> &grid,int i,int j){
    if(i == 0 && j == 0) return grid[0][0];
    int ans = INT_MAX;
    if(i-1 >= 0) ans = sol(grid,i-1,j);
    if(j-1 >= 0) ans = min(ans,sol(grid,i,j-1));
    return grid[i][j]+ans;
} 
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return sol(grid,n-1,m-1);
}
// -------------------------- Memoization -------------------------------//

int sol(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    if(i-1 >= 0) ans = sol(grid,i-1,j,dp);
    if(j-1 >= 0) ans = min(ans,sol(grid,i,j-1,dp));
    dp[i][j] = grid[i][j]+ans;
    return  dp[i][j];
} 
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    dp[0][0] = grid[0][0];
    return sol(grid,n-1,m-1,dp);
}

// -------------------------- DP -------------------------------//

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i = 0;i<n;i++){
        for(int j = 0; j < m; j++){
            int ans = INT_MAX;
            if(i == 0 && j == 0) ans = 0;
            if(i-1 >= 0) ans = dp[i-1][j];
            if(j-1 >= 0) ans = min(ans,dp[i][j-1]);
            dp[i][j] = grid[i][j]+ans;  
        }
    }
    return dp[n-1][m-1];
}
// -------------------------- Space Optimization -------------------------------//
// only dp[i-1] and dp[i] is accessed every time so convert them to cur and prev
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m,0);
    vector<int> cur(m,0);

    for(int i = 0;i<n;i++){
        for(int j = 0; j < m; j++){
            int ans = INT_MAX;
            if(i == 0 && j == 0) ans = 0;
            if(i-1 >= 0) ans = prev[j];
            if(j-1 >= 0) ans = min(ans,cur[j-1]);
            cur[j] = grid[i][j]+ans;  
        }
        prev = cur;
    }
    return prev[m-1];
}
