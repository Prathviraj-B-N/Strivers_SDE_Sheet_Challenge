// ignore if an element is not the starting element
// apply brute force for each starting elements

// O(N)
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(),nums.end());
    int ans = 0;
    for(auto x: nums){
        if(st.find(x-1)!=st.end()) continue; // cant be starting node
        else{
            int count = 1;
            // only runs for starting node so every element is actually visited only once
            while(st.find(x+1)!=st.end()){
                count++;
                x++;
            }
            ans = max(ans,count);
        }
    }
    return ans;
}