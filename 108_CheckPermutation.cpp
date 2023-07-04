#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    
    set<char> st1;    
    set<char> st2;


    for(int i = 0; i < str1.length(); i++){
        st1.insert(str1[i]);
    }

    for(int i = 0; i < str2.length(); i++){
        st2.insert(str2[i]);
    }

    if(st1.size() != st2.size()) return false;

    for(auto x:st1){
        if(st2.find(x)==st2.end()) return false;
    }

    return true;

}