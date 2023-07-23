
// -------------------------- Memoization -------------------------------//
int sol(vector<int> &rack,int idx,int previdx,vector<vector<int>> &dp){
	if(idx == -1) return 0;

	if(dp[idx][previdx+1] != -1) return dp[idx][previdx+1];
	//pick
	int ans = INT_MIN;	
	if(previdx==-1 || rack[previdx] > rack[idx]) ans = rack[idx]+ sol(rack,idx-1,idx,dp);
	
	//not pick
	ans = max(ans,sol(rack,idx-1,previdx,dp));
	dp[idx][previdx+1] = ans;
	return ans;
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return sol(rack,n-1,-1,dp);
}

// -------------------------- DP -------------------------------//
// T O(n^2) S O(n^2)
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));

	for(int idx = n-1; idx >=0 ; idx--){
		for(int previdx = idx-1; previdx >= -1; previdx--){
			int ans = INT_MIN;	
			if(previdx==-1 || rack[idx] > rack[previdx]) ans = rack[idx]+ dp[idx+1][idx+1];			
			ans = max(ans,dp[idx+1][previdx+1]);
			dp[idx][previdx+1] = ans;
		}
	}
	return dp[0][0];
}

// -------------------------- Space Optimization -------------------------------//
// T O(n^2) S O(n)
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<int> cur(n+1,0);
	vector<int> next(n+1,0);

	for(int idx = n-1; idx >=0 ; idx--){
		for(int previdx = idx-1; previdx >= -1; previdx--){
			int ans = INT_MIN;	
			if(previdx==-1 || rack[idx] > rack[previdx]) ans = rack[idx]+ next[idx+1];			
			ans = max(ans,next[previdx+1]);
			cur[previdx+1] = ans;
		}
		next = cur;
	}
	return next[0];
}