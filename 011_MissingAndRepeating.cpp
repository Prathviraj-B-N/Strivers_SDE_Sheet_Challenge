#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int dp[n+1];
	memset(dp,0,sizeof(dp));

	int rep = -1;

	for(auto x:arr){
		dp[x]++;
		if(dp[x]>1) rep = x;
	}	

	for(int i = 1; i< n+1;i++){
		if(dp[i] == 0){
            return {i,rep};
        }
	}

	return {};
}
