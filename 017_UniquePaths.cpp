#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {

	vector<int> dp(n,1);

	for(int i = 1; i < m; i++){
		for(int j = 0; j < n; j++){
			dp[j] = dp[j] +((j-1>=0)?dp[j-1]:0);
		}
	}
	return dp[n-1] ;
}