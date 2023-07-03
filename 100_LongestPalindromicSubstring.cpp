#include<bits/stdc++.h>
string longestPalinSubstring(string str)
{
    int n = str.size();
    vector<vector<bool>> dp(n,vector<bool>(n,false));

    // single char is a pal
    int start = 0;
    int maxLen = 1;
    for(int i = 0; i < n; i++) dp[i][i] = true;
    
    // for len 2
    // we have to do 2 len seperate because i+1 will cross j-1 
    bool vis = false;
    for(int i = 0; i < n-1;i++){
      if (str[i] == str[i + 1]) {
        dp[i][i+1] = true;
        if(!vis){
            start = i;
            maxLen = 2;
            vis = true;
        }
      }
    }

    // for substr size 3 to n
    for(int k = 3; k <= n; k++){
        for(int i = 0; i < n-k+1;i++){
            int j = i+k-1;
            if (dp[i + 1][j - 1] && str[i] == str[j]) {
              dp[i][j] = true;
              if(k > maxLen){
                start = i;
                maxLen = k;
              }
            }
        }
    }

    return str.substr(start,maxLen);
    
}