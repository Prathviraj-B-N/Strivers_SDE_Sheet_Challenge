#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    int n = v.size();
    vector<vector<int>> ans;
    // generate all combinations
    for(int combination = 0 ; combination < (1<<n); combination++){
        vector<int> temp;

        // for each combination traverse from rght to left
        // take 1 and left shift it from 1 to n
        // if bit is one then pick curBit's element
        for(int curBit = 0; curBit < n; curBit++){
            if(combination & (1<<curBit)){
                //pick
                temp.push_back(v[curBit]);
            }

        }
        ans.push_back(temp);
    }
    return ans;
}