#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    unordered_map<int,int> mp; // {ele, most recent index}
    vector<int> ans;
    int n = arr.size();
    
    for(int i = 0; i < k; i++){
        mp[arr[i]] = i;
    }
    ans.push_back(mp.size());
    
    int i = 0;
    int j = k;

    while(j < n){
        //remove ith ele
        if(mp.find(arr[i])!=mp.end()){
            if(mp[arr[i]] < j-k+1) mp.erase(arr[i]);
        }
        i++;
        //insert jth ele
        mp[arr[j]] = j;
        j++;
        ans.push_back(mp.size());
    }
    return ans;
	
}
