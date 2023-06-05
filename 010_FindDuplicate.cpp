#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	unordered_map<int,int> mp;

	for(auto x:arr){
		mp[x]++;
		if(mp[x] > 1)return x;
	}

	return 0;
}
