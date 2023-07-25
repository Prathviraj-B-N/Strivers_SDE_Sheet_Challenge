// -------------------------- Recursion -------------------------------//
// T O(n^n) S
int sol(vector<int> &price,int n){
	int ans = INT_MIN;
	ans = max(ans,price[n-1]); //sell rod as it is
	
    // or sell by cutting it to 2 pieces i.e i ans n-i
    // since we know price [i] just calculate sol(n-i) 
    for(int i = 1;i<n;i++){
		ans = max(ans,price[i-1] + sol(price,n-i));
	}
	return ans;
}
int cutRod(vector<int> &price, int n)
{
	return sol(price,n);
}

// -------------------------- Memoization -------------------------------//

int sol(vector<int> &price,int n,vector<int> &dp){
	if(dp[n]!= -1) return dp[n];
	int ans = INT_MIN;
	for(int i = 1;i<n;i++){
		ans = max(ans,price[i-1] + sol(price,n-i,dp));
	}
	ans = max(ans,price[n-1]);
	dp[n] = ans;
	return ans;
}
int cutRod(vector<int> &price, int n)
{
	// n is domain it can go from 1 to n
	vector<int> dp(n+1,-1); // holds max values
	return sol(price,n,dp);
}

// -------------------------- DP -------------------------------//
int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1,0);
	
	for(int i = 1; i <=n ;i++){
		int ans = INT_MIN;
		for(int j = 1;j<i;j++) ans = max(ans,price[j-1] + dp[i-j]);
		
        ans = max(ans,price[i-1]);
		
        dp[i] = ans;	
	}
	return dp[n];
}
