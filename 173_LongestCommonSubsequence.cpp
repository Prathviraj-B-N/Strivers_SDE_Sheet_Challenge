#include<bits/stdc++.h>

// recursion
int sol(string s,string t,int i,int j,int n,int m){  
	if(i == n || j == m) return 0;
	int ans = 0;
	if(s[i] == t[j]){
		ans =  1 + sol(s,t,i+1,j+1,n,m);
	}else{
		ans = 0 + sol(s,t,i+1,j,n,m);
		ans = max(ans,0 + sol(s,t,i,j+1,n,m));
	}
	return ans;
}

// DP solution
int lcs(string s, string t)
{

	int n = s.length();
	int m = t.length();
	if(m > n) {
		lcs(t,s);
	}	
	vector<vector<int>> dp(n,vector<int>(m,0));

	for(int i = 0; i < n;i++){
		for(int j = 0; j < m; j++){
			int ans = 0;
			if(s[i] == t[j]){
				ans = 1;
				if(i>0 && j>0) ans += dp[i-1][j-1];
			}else{
				if(i > 0 ) ans = 0 + dp[i-1][j];
				if(j > 0) ans = max(ans,0 + dp[i][j-1]);
			}
			dp[i][j] = ans;
		}

	}
	return dp[n-1][m-1];

}