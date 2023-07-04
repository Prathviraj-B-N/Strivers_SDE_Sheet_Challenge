#include <bits/stdc++.h> 

bool comp(pair<int,int> a, pair<int,int> b){
    return a.second>b.second;
}

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int,int> mp;

    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    
    vector<pair<int,int>> temp;
    for (auto it : mp) {
        temp.push_back(it);
    }
    sort(temp.begin(),temp.end(),comp);
    set<int> ans1;

    for(auto it : temp){
      if (k) {
        ans1.insert(it.first);
        k--;
      }
    }
    vector<int> ans(ans1.begin(),ans1.end());
    return ans;

}