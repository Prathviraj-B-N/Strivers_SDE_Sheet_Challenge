#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int numRows) 
{
    vector<vector<long long int>> ans;
    ans.push_back({1});
    if(numRows == 1) return ans;
        ans.push_back({1,1});
        for(int i = 2;i<numRows;i++){
            ans.push_back({1});
            for(int j = 1;j < i;j++){
                ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ans[i].push_back(1);
        }
        return ans;
}
