class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> mp = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        vector<string> ans;
        string first = mp[digits[0]-'0'];

        for(auto x:first) {
            string s(1,x);
            ans.push_back(s);
        }

        int i = 1;
        while(i < digits.size()){
            vector<string> temp;
            string a = mp[digits[i]-'0'];
            for(auto x:ans){
                for(int j = 0; j < a.size(); j++){
                    temp.push_back(x+a[j]);
                }
            }
            ans = temp;
            i++;
        }
        return ans;
    }
};