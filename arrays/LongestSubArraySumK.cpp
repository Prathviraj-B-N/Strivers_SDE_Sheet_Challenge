int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = 0;
    int ans = 0;
    int i = 0;
    int j = 0;
    int n = a.size();
    
    while(j < n){
        if(i > j) j = i;
        sum += a[j];
        if(sum == k) ans = max(ans,j-i+1);

        while(sum >= k){
            if(sum == k){
                 ans = max(ans,j-i+1);
                 break;
            }
            sum -= a[i++];
        }
        j++;
    }
    return ans;
    
}

// prefix sum approach
int getLongestSubarray(vector<int>& nums, int k){
    unordered_map<int,int> mp;
    mp[0] = -1;
    int n = nums.size();
    int prefixSum = 0;
    int ans = 0;
    
    for(int i = 0;i < n; i++){
        prefixSum+=nums[i];
        if(mp.find(prefixSum)==mp.end())mp[prefixSum] = i;
        if(mp.find(prefixSum-k)!=mp.end()){
            int idx = mp[prefixSum-k];
            ans = max(ans,i-idx);
        }
    }
    
    return ans;
}
