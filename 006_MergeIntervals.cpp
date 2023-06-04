#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
     vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        int start = intervals[0][0];
        int endd   = intervals[0][1];
        int n = intervals.size();

        for(int i = 0; i<n ;i++){
            if(intervals[i][0] <= endd){
                endd = max(intervals[i][1],endd);
            }
            else{
                ans.push_back({start,endd});
                start = intervals[i][0];
                endd = intervals[i][1];
            }            
        }
        ans.push_back({start,endd});

        return ans;
}
