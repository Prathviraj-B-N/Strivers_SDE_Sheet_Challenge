#include<queue>
// #include<algorithm>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int, vector<int>, greater<int>> minHeap(k);
	priority_queue<int> maxHeap(k);

	int i;
	for(i = 0; i < k; i++){
		minHeap.push(arr[i]);
		maxHeap.push(arr[i]);
	}

	while(i < n){
		if(arr[i] > minHeap.top()){
			minHeap.pop();
			minHeap.push(arr[i]);
		}
		if(arr[i] < maxHeap.top()){
			maxHeap.pop();
			maxHeap.push(arr[i]);
		}
		i++;
	}

	return {maxHeap.top(),minHeap.top()};

	// sort(arr.begin(),arr.end());

	// return {arr[k-1],arr[n-k]};

}