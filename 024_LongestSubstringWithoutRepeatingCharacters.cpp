#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int n =s.size();
    if(n <= 1) return n;

    unordered_set<char> st;
    
    int r = 0;
    int l = 0;

    int curLen = 0;
    int maxLen = 1;

    while(l<=r && r<n){
        if(l == r){
            st.insert(s[r]);
            r++;
            curLen++;
            continue;
        }
        if(st.find(s[r])!=st.end()){
            st.erase(s[l]);
            curLen--;
            l++;
        }
        else{
            curLen++;
            maxLen = max(maxLen,curLen);
            st.insert(s[r]);
            r++;
        }
    } 

    return maxLen;
}