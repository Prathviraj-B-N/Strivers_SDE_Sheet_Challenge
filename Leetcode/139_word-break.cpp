class Solution {
public:
    int isMatch(string &s1,int idx,string &s2){
        for(int i = idx; i < min(s1.size(),s2.size()+idx); i++){
            if(s1[i] != s2[i-idx]) return -1;
        }
        return s2.length();
    }
    bool sol(int idx,string &s,vector<string> &wordDict){
        if(idx == s.size()) return true;
        for(auto x:wordDict){
            int match = isMatch(s,idx,x);
            if(match != -1){
                if(sol(idx+match,s,wordDict)) return true;
            }
        }
        return false;
    }   

    bool wordBreak(string s, vector<string>& wordDict) {
        return sol(0,s,wordDict);
    }
};