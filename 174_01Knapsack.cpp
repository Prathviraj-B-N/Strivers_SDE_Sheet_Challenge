// Recursion
int sol(vector<int> &values,vector<int> &weights,int idx,int n,int w){

	if(idx == n) return 0;
	// pick
	int ans = 0;
	if((w-weights[idx]) >= 0) ans = values[idx] + sol(values,weights,idx+1,n,w-weights[idx]);
	
	//not pick
	ans = max(ans,0 + sol(values,weights,idx+1,n,w));

	return ans;
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<int> dp(n,0); // store profit
	return sol(values,weights,0,n,w);
}
// ------------------------------------------------------------------------------------ //
// Memoization
int sol(vector<int> &values,vector<int> &weights,int idx,int n,int w,vector<vector<int>> &dp){

	if(idx == n) return 0;
	// pick
	int ans = 0;
	if(dp[idx][w] != -1) return dp[idx][w];
	if((w-weights[idx]) >= 0) ans = values[idx] + sol(values,weights,idx+1,n,w-weights[idx],dp);
	
	//not pick
	ans = max(ans,0 + sol(values,weights,idx+1,n,w,dp));
	dp[idx][w] = ans;
	return ans;
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n,vector<int>(1000,-1)); // store profit
	return sol(values,weights,0,n,w,dp);
}
// ------------------------------------------------------------------------------------ //
