// brute force
int kthLargest(vector<int>& arr, int size, int K)
{
	sort(arr.begin(),arr.end());
	return arr[size-K];
}

// using min heap
int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int,vector<int>, greater<int>> q;
	for(int i = 0;i < K;i++){
		q.push(arr[i]);
	}

	for(int i = K; i < size;i++){
		if(q.top() < arr[i]) {
			q.pop();
			q.push(arr[i]);
		}
	}
	return q.top();
}