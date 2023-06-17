// O(n * len) + O(n * len) len varies for each string

#include <bits/stdc++.h> 
struct Trie{

    Trie* reference[26];
    bool flag = false;

    bool doesExist(char ch){
        return (reference[ch-'a']!=NULL);
    }

    Trie* get(char ch){
        return reference[ch-'a'];
    }

    void put(char ch){
        reference[ch-'a'] = new Trie();
    }

};

void insert(string &s, Trie *node){
    for(int i = 0; i < s.size(); i++){
        if(!node->doesExist(s[i])) node->put(s[i]);
        node = node->get(s[i]);
    }
    node->flag = true;
}

string completeString(int n, vector<string> &a){
    Trie *root = new Trie();

    for(auto s:a){
        insert(s,root);
    }

    string longest="";
    for(auto s:a){
        Trie* node =root;
        for(int i = 0; i < s.size(); i++){
            if(node->doesExist(s[i])){
                node = node->get(s[i]);
                if(!node->flag) break;
            }
        }
        if(node->flag){
            if(longest.size() < s.size()){
                longest = s;
                continue;
            }

            if(longest.size() == s.size() && longest > s){
                 longest = s;
            }
        }
    }

    if(longest == "") return "None"; 

    return longest;
}