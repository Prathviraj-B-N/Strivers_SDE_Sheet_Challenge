int removeDuplicates(vector<int> &arr, int n) {
	int idx = 1;

	int i = 1;
	while(i<n){
		if(arr[i] == arr[i-1]) i++;
		else{
			arr[idx++] = arr[i++];
		}
	}
	return idx;
}