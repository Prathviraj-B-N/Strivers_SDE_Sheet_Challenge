// -------------------------- Recursion -------------------------------//
// T O(3^n) S O(4^n) 
int sol(string &s,string &t,int i,int j){
    if(i < 0) return j+1;
    if(j < 0) return i+1;


    if(s[i] == t[j]) return sol(s,t,i-1,j-1);

    //insert
    int a = 1+sol(s,t,i,j-1);

    //delete
    int b = 1+sol(s,t,i-1,j);

    //replace
    int c = 1+sol(s,t,i-1,j-1);

    return min(a,min(b,c));
}
int editDistance(string str1, string str2)
{
    return sol(str1,str2,str1.size()-1,str2.size()-1);
}

// -------------------------- Memoization -------------------------------//
// T O(n*m) S O(n*m) + O(n+m)
int sol(string &s,string &t,int i,int j,vector<vector<int>> &dp){
    if(i < 0) return j+1;
    if(j < 0) return i+1;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]) return sol(s,t,i-1,j-1,dp);

    //insert
    int a = 1+sol(s,t,i,j-1,dp);

    //delete
    int b = 1+sol(s,t,i-1,j,dp);

    //replace
    int c = 1+sol(s,t,i-1,j-1,dp);
    dp[i][j] = min(a,min(b,c));
    return dp[i][j];
}
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    return sol(str1,str2,n-1,m-1,dp);
}

// -------------------------- DP -------------------------------//
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    // if i == 0, s has been completed and remaining elements of t has to be deleted
    for(int i = 0; i <= n;i++) dp[i][0] = i;
    // if j == 0, t has been completed and remaining elements of s has to be deleted
    for(int i = 0; i <= m;i++) dp[0][i] = i;

    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m;j++) {
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                //insert
                int a = dp[i][j-1];

                //delete
                int b = dp[i-1][j];

                //replace
                int c = dp[i-1][j-1];
                dp[i][j] = 1 + min(a,min(b,c));
            }
        }
    }
    return dp[n][m];

}



// -------------------------- Space Optimization -------------------------------//
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    
    vector<int> dpprev(m+1,0);
    vector<int> dpcur(m+1,0);
    
    for(int i = 0; i <= m;i++) dpprev[i] = i;

    for(int i = 1; i <= n;i++){
        dpcur[0] = i; // instead of having a dp for col, update cur[0] at each step
        for(int j = 1; j <= m;j++) {
            if(str1[i-1] == str2[j-1]) dpcur[j] = dpprev[j-1];
            else{
                //insert
                int a = dpcur[j-1];

                //delete
                int b = dpprev[j];

                //replace
                int c = dpprev[j-1];

                dpcur[j] = 1 + min(a,min(b,c));
            }
        }
        dpprev = dpcur;

    }
    return dpprev[m];

}