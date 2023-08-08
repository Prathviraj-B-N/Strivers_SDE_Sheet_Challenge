class Solution {
public:
    bool check(vector<int>& nums, int allowedSum,int k){
        int curIdx = 0;
        for(int i = 0; i < k; i++){
            int curSum = 0;
            while(curIdx < nums.size() && curSum+nums[curIdx] <= allowedSum){
                curSum+=nums[curIdx++];
            }
        }
        if(curIdx == nums.size()) return true;
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = 0;
        int h = 0;
        for(int i = 0; i < nums.size(); i++){
            h += nums[i];
            l = max(l,nums[i]);
        }

        while(l<=h){
            int mid = l+(h-l)/2;
            if(check(nums,mid,k)){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }

        return l;
    }
};

// largest (sum of subarray) among subarrays is minimized 
// 7 2 5 10 8 , k = 2
// bin search on max subarray sum

// l = 10 h = 32 mid = 21
// 7+2+5 , 10+8 , whole arr traversed and split into k subarrays so true therefore ans can be 21 so h = mid-1;

// l = 10 h = 20 mid = 15
// 7+2+5 , 10 , _ ; whole arr not traversed i >= k so false

// l = 16 h = 20 mid = 18
// 7+2+5, 10+8 true try to minimize

// l = 16 h = 17 mid = 16
// 7+2+5 , 10 ; while arr not traversed so false

// l = 17 h = 17 mid = 17
// 7+2+5, 10 ... false

// l = 18 h = 17 break return l