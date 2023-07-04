#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int j = 0;
    int n = nums.size();
    deque<pair<int,int>> q; // idx, val
    vector<int> ans;
    
    while(j<n){
        
        //remove out of idx elements
        while(!q.empty() && q.front().first < j-k+1) q.pop_front();

        if(q.empty()) q.push_back({j,nums[j]});
        else if(nums[j] < q.back().second){
            q.push_back({j,nums[j]});
        }
        else{
            while(!q.empty() && nums[j] >= q.back().second) q.pop_back();
            q.push_back({j,nums[j]});
        }

        if(j+1>=k) ans.push_back(q.front().second);
        j++;
    }

    return ans;
}
// maintain queue in descending order