int singleNonDuplicate(vector<int>& arr)
{
	int l = 0;
	int r = arr.size()-1;
	int n = arr.size();

	while(l<=r){
		int mid = (l+r)/2;

		if((mid == 0 || arr[mid] != arr[mid-1]) && (mid == n-1 || arr[mid]!=arr[mid+1])) return arr[mid];

		if(mid%2 == 0){
			if(arr[mid] == arr[mid+1]){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}else{
			if(arr[mid-1] == arr[mid]){
				l = mid+1;
			}else{
				r = mid-1;
			}
		}

	}

	return -1;
}