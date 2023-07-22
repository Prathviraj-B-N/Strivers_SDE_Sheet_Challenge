#include <bits/stdc++.h> 

// its always either suffix or prefix
// think in terms of number of negatives , odd negatives ,even negatives and 0;
int maximumProduct(vector<int> &arr, int n)
{
	int prefix = 1;
	int suffix = 1;
	int ans = INT_MIN;

	for(int i = 0 ;i < n;i++){

		if(prefix == 0) prefix = 1;
		if(suffix == 0) suffix = 1;

		prefix = prefix * arr[i];
		suffix = suffix * arr[(n-1)-i];
		ans = max(ans,max(prefix,suffix));

	}
	return ans;
}