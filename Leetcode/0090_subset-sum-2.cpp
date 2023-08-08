class Solution {
public:
    void sol(vector<int>& nums,vector<int> temp,set<vector<int>>& st,int idx,int n){

        st.insert(temp);
        for(int i = idx; i <n; i++){
            temp.push_back(nums[i]);
            sol(nums,temp,st,i+1,n);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        sol(nums,{},st,0,nums.size());

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};