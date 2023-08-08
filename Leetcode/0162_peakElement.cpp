int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    
    int l = 0;
    int r = n-1;

    while(l <= r){
        int mid = l+(r-l)/2;

        int prev = (mid < 1)?INT_MIN:nums[mid-1];
        int next = (mid >= n-1)?INT_MIN:nums[mid+1];

        if(nums[mid] > prev && nums[mid] > next) return mid;

        if(prev > next) r = mid-1;
        else l = mid+1;
    }

    return 0;
}