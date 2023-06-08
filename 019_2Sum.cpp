// T: O(n^2) + O(m*logm) : m -> size of ans; n -> size of arr;

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int k){
   unordered_map<int,vector<int>> mp;
   int n = arr.size();
   vector<vector<int>> ans;
   
   for(int i = 0; i < n; i++){        // O(n)
      if(mp.find(k-arr[i])!=mp.end()){
         for(auto x:mp[k - arr[i]]){ // worst case for last element all n-1 elements are in map[k-arr[i]] O(n)
            if(arr[x] <= arr[i]) ans.push_back({ arr[x] , arr[i] });
            else ans.push_back({ arr[i] , arr[x] });
         }
      }
      mp[arr[i]].push_back(i);

   }
   sort(ans.begin(),ans.end()); // O(mlogm) : m is size of ans
   return ans;
}