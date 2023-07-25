// -------------------------- Recursion -------------------------------//
bool exists(string s,unordered_set<string> &st){
    return st.find(s)!=st.end();
}

bool sol(int i, string& target, std::unordered_set<string>& st) {
    if (i == target.length()) return true;    
    
    for (int j = i + 1; j <= target.length(); j++) {
        string s = target.substr(i, j - i);
        if (exists(s, st) && sol(j, target, st)) {
            return true;
        }
    }
    return false;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_set<string> st;

    for(auto x:arr){
        st.insert(x);
    }

    return sol(0,target,st);
    
}

// -------------------------- Memoization -------------------------------//
bool sol(int i, string& target, std::unordered_set<string>& st,vector<int> &dp) {
    if (i == target.length()) return true;    
    if(dp[i] != -1) return (dp[i]==1)?true:false;
    for (int j = i + 1; j <= target.length(); j++) {
        string s = target.substr(i, j - i);
        if (exists(s, st) && sol(j, target, st,dp)) {
            dp[i] = 1;
            return true;
        }
    }

    dp[i]=0;
    return false;
}