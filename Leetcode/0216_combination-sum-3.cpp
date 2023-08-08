class Solution {
public:
    void sol(int sum,int cur,vector<int> temp,int k,int &n,vector<vector<int>> &ans){
        if(k == 0){
            if(sum == n){
                ans.push_back(temp);
            }
            return;
        }
        if(sum > n) return;
        
        for(int i = cur;i <= 9;i++){
            sum += i;
            temp.push_back(i);
            sol(sum,i+1,temp,k-1,n,ans);
            temp.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        sol(0,1,{},k,n,ans);
        return ans;
    }
};