#include<algorithm>
#include<set>
void sol(int idx,vector<int>& arr,vector<int> temp,set<vector<int>>& ans, int target,int n){
	if(target == 0) {
		sort(temp.begin(),temp.end());
		ans.insert(temp);
		return;
	}
	if(idx == n || target < 0){
		return;
	}

	for(int i = idx; i < n; i++){
		if(i>idx && arr[i-1]==arr[i]) continue;
		temp.push_back(arr[i]);
		sol(i+1,arr,temp,ans,target-arr[i], n);
		temp.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	set<vector<int>> ans;
	sort(arr.begin(),arr.end());
  	sol(0, arr, {},ans,target,n);
	vector<vector<int>> anss(ans.begin(),ans.end());
	return anss;
}
