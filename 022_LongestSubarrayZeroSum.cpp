// T: O(n-1) + O(n) = O(n)
// T: O(n^2) in worst case because of unordered map
// S: O(n)

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
  
  int n = arr.size();
  int ans = 0;
  vector<int> prefix(n,0);
  prefix[0] = arr[0];

  for(int i = 1 ; i < n; i++){
    prefix[i] = arr[i]+prefix[i-1];
  }

  unordered_map<int,int> mp;
  mp[0] = -1; // if prefix is zero then 0 to i 's sum is 0

  for(int i = 0 ; i < n ; i++){
    // if(prefix[i] == 0){ ans = max(ans, i+1); continue;} instead of mp[0] = -1; is more readable code
    if(mp.find(prefix[i])!=mp.end()){
      ans = max(ans, i - mp[prefix[i]]);
    }else{
      mp[prefix[i]] = i;
    }
  }
  
  return ans;

}