// O(n^2 log k + klogk)
#include <bits/stdc++.h> 
bool cmp(int a,int b){
	return a > b;
}
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(minHeap.size() < k) minHeap.push(a[i]+b[j]);
			else if(a[i]+b[j] > minHeap.top()){
				minHeap.pop();
				minHeap.push(a[i]+b[j]);
			}
		}
	}

	vector<int> ans;
	for(int i = 0; i < k; i++){
		ans.push_back(minHeap.top());
		minHeap.pop();
	}

	sort(ans.begin(),ans.end(),cmp);
	return ans;
}